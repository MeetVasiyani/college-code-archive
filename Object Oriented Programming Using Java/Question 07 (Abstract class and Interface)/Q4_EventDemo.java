/* Create interface EventListener with performEvent() method. Create MouseListener interface which inherits EventListener 
along with mouseClicked(), mousePressed(), mouseReleased(), mouseMoved(), mouseDragged() methods. Also create 
KeyListener interface which inherits EventListener along with keyPressed(), keyReleased() methods. WAP to create 
EventDemo class which implements MouseListener and KeyListener and demonstrate all the methods of the interfaces. */

interface EventListener {
    void performEvent();
}

interface MouseListener extends EventListener {
    void mouseClicked();
    void mousePressed();
    void mouseReleased();
    void mouseMoved();
    void mouseDragged();
}

interface KeyListener extends EventListener {
    void keyPressed();
    void keyReleased();
}

public class Q4_EventDemo implements MouseListener, KeyListener {

    @Override
    public void performEvent() {
        System.out.println("Performing an event");
    }

    @Override
    public void mouseClicked() {
        System.out.println("Mouse Clicked");
    }

    @Override
    public void mousePressed() {
        System.out.println("Mouse Pressed");
    }

    @Override
    public void mouseReleased() {
        System.out.println("Mouse Released");
    }

    @Override
    public void mouseMoved() {
        System.out.println("Mouse Moved");
    }

    @Override
    public void mouseDragged() {
        System.out.println("Mouse Dragged");
    }

    @Override
    public void keyPressed() {
        System.out.println("Key Pressed");
    }

    @Override
    public void keyReleased() {
        System.out.println("Key Released");
    }

    public static void main(String[] args) {
        Q4_EventDemo eventDemo = new Q4_EventDemo();

        eventDemo.performEvent();
        eventDemo.mouseClicked();
        eventDemo.mousePressed();
        eventDemo.mouseReleased();
        eventDemo.mouseMoved();
        eventDemo.mouseDragged();

        eventDemo.keyPressed();
        eventDemo.keyReleased();

        eventDemo.performEvent();
    }
}
