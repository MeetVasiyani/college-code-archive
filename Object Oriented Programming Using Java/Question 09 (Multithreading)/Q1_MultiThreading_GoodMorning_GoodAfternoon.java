/*Write an application that executes two threads. One thread displays "Good Morning" every 1000 milliseconds & another 
thread displays "Good Afternoon" every 3000 milliseconds. Create the threads by implementing the Runnable interface. */
public class Q1_MultiThreading_GoodMorning_GoodAfternoon {

    public static void main(String[] args) {

        Runnable goodMorningTask = new Runnable() {
            @Override
            public void run() {
                while (true) {
                    
                    System.out.println("Good Morning");
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };
        Runnable goodAfternoonTask = new Runnable() {
            @Override
            public void run() {
                while (true) {
                    System.out.println("Good Afternoon");
                    try {
                        Thread.sleep(3000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };

        // Create and start the threads
        Thread goodMorningThread = new Thread(goodMorningTask);
        Thread goodAfternoonThread = new Thread(goodAfternoonTask);
        goodMorningThread.start();
        goodAfternoonThread.start();
    }
}
