/**
 * @file: type.h
 * @author: Anonyman637
 * @date: 8/26/2021; 3:33 PM
 */

#ifndef DATASTRUCTURESCOURSE_TYPE_H
#define DATASTRUCTURESCOURSE_TYPE_H

/**
 * @brief
 * Any is the generic struct that holds the data and type metadata.
 *
 * All generic variables are of type any.
 */
typedef struct Any Any;

/**
 * Syntactic sugar of using let in variable declarations of generic types.
 */
typedef struct Any *let;

/**
 * @struct Type
 *
 * @brief
 * Type metadata of generic variables for smooth operability between types.
 *
 * Type contains function references to perform some fundamentally generic operations
 * like copy, compare, print, free and more to be added later.
 *
 * These functions define the behaviour of the type.
 * Types have polymorphic properties but not have inheritance properties.
 */
typedef struct Type {
	
	/**
	 * @brief
	 * Unique type name in string.
	 */
	char *typeName;
	
	/**
	 * @brief
	 * Deep copies any given variable and returns clone.
	 *
	 * @param this the variable to deep copy
	 *
	 * @return deep copy of the passed variable
	 */
	Any *(*clone)(Any *this);
	
	/**
	 * @brief
	 * Compares any two passed variables.
	 *
	 * @param this the variable to compare against
	 * @param other another variable
	 *
	 * @return negative integer if this is less than other; zero if they are equal
	 * and positive integer if this is greater than other
	 */
	int (*compare)(Any *this, Any *other);
	
	/**
	 * @brief
	 * Prints the string representation of the variable in terminal.
	 *
	 * @note
	 * Needs to be replaced with toString method when memory could be automatically manageable.
	 *
	 * @param this the variable of which string representation needs to be printed.
	 */
	void (*print)(Any *this);
	
	/**
	 * @brief
	 * Frees the memory associated with the passed variable.
	 *
	 * @param this the variable of whose memory and data needs to freed
	 */
	void (*destroyData)(Any *this);
	
	Any *(*add)(Any *this, Any *other);
} Type;

/**
 * @brief
 * Creates a generic type metadata with a type name.
 *
 * @param typeName name of the type
 *
 * @return pointer to newly created Type
 */
Type *type_new(char *typeName);

/**
 * @brief
 * Frees the memory occupied by the instance of Type.
 *
 * @param type pointer to Type instance
 */
void type_destroy(Type *type);

/* ============================== Generic Type ========================= */

/**
 * @struct Any
 *
 * @brief
 * Holds the data of the variable in a generic pointer
 * and pointer to type interface implementation.
 */
struct Any {
	/**
	 * @brief
	 * Generic pointer to the struct of data of the variable.
	 */
	void *data;
	
	/**
	 * @brief
	 * Pointer to the type instance of the variable.
	 */
	Type *type;
};

/**
 * @brief
 * Creates a variable with data and type metadata.
 *
 * @param data generic pointer to the data of the variable
 * @param type instance of Type to associate type metadata
 *
 * @return pointer to Any instance
 */
Any *any_new(void *data, Type *type);

/**
 * @brief
 * Unique type name in string.
 */
char *any_type(Any *this);

/**
 * @brief
 * Deep copies any given variable and returns clone.
 *
 * @param this the variable to deep copy
 *
 * @return deep copy of the passed variable
 */

Any *any_clone(Any *this);

/**
 * @brief
 * Compares any two passed variables.
 *
 * @param this the variable to compare against
 * @param other another variable
 *
 * @return negative integer if this is less than other; zero if they are equal
 * and positive integer if this is greater than other
 */
int any_compare(Any *this, Any *other);

/**
 * @brief
 * Prints the string representation of the variable in terminal.
 *
 * @note
 * Needs to be replaced with toString method when memory could be automatically manageable.
 *
 * @param this the variable of which string representation needs to be printed.
 */
void any_print(Any *this);

/**
 * @brief
 * Frees the memory occupied by instance of Any
 *
 * @param this pointer to Any instance
 */
void any_destroy(Any *this);

Any *any_add(Any *this, Any *other);

#endif //DATASTRUCTURESCOURSE_TYPE_H
