/**
 * @file: primitives.h
 * @author: Anonyman637
 * @date: 8/26/2021; 8:28 PM
 */#ifndef DATASTRUCTURESCOURSE_PRIMITIVES_H
#define DATASTRUCTURESCOURSE_PRIMITIVES_H

#include "int.h"
#include "string.h"

#define t_primitives_register() \
    t_int_register();   \
    t_string_register()

#define t_primitives_deregister() \
    t_int_deregister(); \
    t_string_deregister()

#endif //DATASTRUCTURESCOURSE_PRIMITIVES_H
