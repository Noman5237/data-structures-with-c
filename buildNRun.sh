echo -n "\nPlease enter the Lab and Task ID (format: LnTn): "
read taskId
echo "\n================ BUILDING $taskId ================"
cmake --build . --target $taskId -- -j 9

echo "\n================ RUNNING $taskId ================"
out/Linux/Debug/$taskId

echo "\n================ FINISHED $taskId ================"