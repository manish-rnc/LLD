In Singleton pattern:
1. more than 1 object cannot be created
2. If more objects are created then it should get the same object ( or the address of the same object which once created )
3. Singleton pattern is not thread safe in multithreaded environment as more than 1 thread can execute simultaneously and might create more than 1 object -> thread safety can be ensured using mutex
