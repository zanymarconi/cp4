package dllgbb.java;

import java.util.concurrent.*;
import java.util.Random;

public class TimeoutExample {

    /** Simulates a slow operation that takes 5-15 seconds */
    private Long slowMethod(Random random) throws InterruptedException {
        int sleepSeconds = 5 + random.nextInt(11); // 5 to 15 seconds
        System.out.println("\tslowMethod started, will take " + sleepSeconds + " seconds...");
        
        long start = System.currentTimeMillis();
        try {
            Thread.sleep(sleepSeconds * 1000L);
        } catch (InterruptedException e) {
            System.out.println("\tslowMethod was interrupted!");
            throw e;
        }
        return System.currentTimeMillis() - start;
    }

    void processItems() {
        ExecutorService executor = Executors.newSingleThreadExecutor();
        Random random = new Random();

        // Process multiple items to see both success and timeout cases
        for (int i = 1; i <= 5; i++) {
            System.out.println("\n--- Processing item " + i + " ---");
            
            Future<Long> future = executor.submit(() -> slowMethod(random)); // Submit the slow task
            try {
                Long result = future.get(10, TimeUnit.SECONDS); // Wait at most 10 seconds for the result
                System.out.println("Success! Method completed in " + result + " ms");
        
            } catch (TimeoutException e) {
                System.out.println("Timeout! Gave up waiting after 10 seconds");
                future.cancel(true); // Interrupt the running task
                
            } catch (InterruptedException e) {
                System.out.println("Main thread was interrupted");
                Thread.currentThread().interrupt();
                
            } catch (ExecutionException e) {
                System.out.println("Task threw an exception: " + e.getCause());
            }
        }

        executor.shutdown();
        System.out.println("\nAll items processed!");
    }

    public static void main(String[] args) {
        new TimeoutExample().processItems();
    }
}
/*

**Key concepts demonstrated:**

1. **`ExecutorService`** - Manages a thread pool for running async tasks

2. **`Future.get(timeout, unit)`** - Waits for the result with a maximum timeout; throws `TimeoutException` if it takes too long

3. **`future.cancel(true)`** - Attempts to interrupt the running task when we give up (the `true` means interrupt if running)

4. **Exception handling** - The three exceptions you need to handle: `TimeoutException`, `InterruptedException`, and `ExecutionException`

*/