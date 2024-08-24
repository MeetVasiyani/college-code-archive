/*Write a program of writing binary file using multithreading. Demonstrate use of join() and yield() interrupt(). */
import java.io.FileOutputStream;
import java.io.IOException;

class WriterThread extends Thread {
    byte[] data;
    FileOutputStream fos;
    final Object lock;

    public WriterThread(byte[] data, FileOutputStream fos, Object lock) {
        this.data = data;
        this.fos = fos;
        this.lock = lock;
    }

    @Override
    public void run() {
        try {
            synchronized (lock) {
                fos.write(data);
                Thread.yield();
            }
        } 
        catch (IOException e) {
            e.printStackTrace();
        } 
        finally {
            try {
                fos.close();
            } 
            catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Q3_Demonstrate_Join_Yeild_Interrupt {
    public static void main(String[] args) {
        byte[] data1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        byte[] data2 = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
        Object lock = new Object();

        try (FileOutputStream fos = new FileOutputStream("output.bin")) {
            WriterThread thread1 = new WriterThread(data1, fos, lock);
            WriterThread thread2 = new WriterThread(data2, fos, lock);

            thread1.start();
            thread2.start();

            thread1.interrupt();

            thread1.join();
            thread2.join();
        } 
        catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}