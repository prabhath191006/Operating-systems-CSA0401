#include <stdio.h>
#include <windows.h>

DWORD WINAPI threadFunction(LPVOID arg) {
    int threadNum = *((int*)arg);
    printf("Thread %d: Hello from thread!\n", threadNum);
    return 0;
}

int main() {
    const int NUM_THREADS = 5;
    HANDLE threads[NUM_THREADS];
    int threadArgs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        threadArgs[i] = i + 1;
        threads[i] = CreateThread(
            NULL,                // default security attributes
            0,                   // default stack size
            threadFunction,      // thread function
            &threadArgs[i],      // argument to thread function
            0,                   // default creation flags
            NULL                 // ignore thread ID
        );

        if (threads[i] == NULL) {
            printf("Error creating thread %d\n", i + 1);
            return 1;
        }
    }

    // Wait for all threads to finish
    WaitForMultipleObjects(NUM_THREADS, threads, TRUE, INFINITE);

    // Close thread handles
    for (int i = 0; i < NUM_THREADS; i++) {
        CloseHandle(threads[i]);
    }

    printf("All threads finished.\n");
    return 0;
}
