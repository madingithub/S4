import java.awt.*;
import java.awt.event.*;

public class EventHandlerDemo {
    private Frame parentFrame;
    private Label headerTitle;
    private Label status;
    private Panel panel;

    public EventHandlerDemo() {
        prepareInterface();
    }

    public static void main(String[] args) {
        EventHandlerDemo awtdemo = new EventHandlerDemo();
        awtdemo.showEventHandlingDemo();
    }

    private void prepareInterface() {
        parentFrame = new Frame("Java Event Handling Example");
        parentFrame.setSize(400, 400);
        parentFrame.setLayout(new GridLayout(3, 1));

        parentFrame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent windowEvent) {
                System.exit(0);
            }
        });

        headerTitle = new Label();
        headerTitle.setAlignment(Label.CENTER);

        status = new Label();
        status.setAlignment(Label.CENTER);
        status.setSize(350, 100);

        panel = new Panel();
        panel.setLayout(new FlowLayout());

        parentFrame.add(headerTitle);
        parentFrame.add(panel);
        parentFrame.add(status);

        parentFrame.setVisible(true);
    }

    private void showEventHandlingDemo() {
        headerTitle.setText("Handling Button Click Event");

        Button firstButton = new Button("First Button");
        Button secondButton = new Button("Second Button");
        Button thirdButton = new Button("Third Button");

        firstButton.setActionCommand("First Button Clicked");
        secondButton.setActionCommand("Second Button Clicked");
        thirdButton.setActionCommand("Third Button Clicked");

        // Registering buttons with the listener
        firstButton.addActionListener(new ButtonClickEventListener());

        secondButton.addActionListener(new ButtonClickEventListener());
        thirdButton.addActionListener(new ButtonClickEventListener());

        panel.add(firstButton);
        panel.add(secondButton);
        panel.add(thirdButton);

        parentFrame.setVisible(true);
    }

    // Inner class implementing ActionListener
    private class ButtonClickEventListener implements ActionListener {
        // Overriding actionPerformed method
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();

            // Do different actions according to different commands
            if (command.equals("First Button Clicked")) {
                status.setText("First Button Clicked.");
            } else if (command.equals("Second Button Clicked")) {
                status.setText("Second Button Clicked.");
            } else {
                status.setText("Third Button Clicked.");
            }
        }
    }
}