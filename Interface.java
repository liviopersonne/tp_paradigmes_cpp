
import javax.swing.*;
import java.awt.event.*;
import java.awt.BorderLayout;

public class Interface extends JFrame {

    JTextArea textArea = new JTextArea("Init Text", 10, 5);
    JButton addLineButton1, addLineButton2, exitButton;
    JPanel buttons = new JPanel();
    private static final long serialVersionUID = 1L;

    public static void main(String argv[]) {
        System.setProperty("java.awt.headless", "true");
        new Interface();
    }

    public Interface() {
        buttons.add(addLineButton1 = new JButton("Add line 1"));
        buttons.add(addLineButton2 = new JButton("Add line 2"));
        buttons.add(exitButton = new JButton("Close"));
        add(textArea, BorderLayout.CENTER);
        add(buttons, BorderLayout.SOUTH);

        addLineButton1.addActionListener(new AddLineListener("Added line 1"));
        addLineButton2.addActionListener(new AddLineListener("Added line 2"));
        exitButton.addActionListener(new CloseListener());

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    class AddLineListener implements ActionListener {

        String line;

        public AddLineListener(String addedLine) {
            line = addedLine;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            textArea.append('\n' + line);
        }
    }

    class CloseListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}
