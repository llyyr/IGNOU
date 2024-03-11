import javax.swing.*;

public class Applet {
    private JTextField tF = new JTextField(1);
    private JTextArea tA = new JTextArea(11, 30);

    public Applet() {
        JFrame F = new JFrame("Number Table Applet");
        F.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel P = new JPanel();
        P.setLayout(new BoxLayout(P, BoxLayout.Y_AXIS));

        JButton B = new JButton("Generate Table");
        B.addActionListener(e -> {
            try {
                int n = Integer.parseInt(tF.getText());
                if (n < 1 || n > 50) throw new NumberFormatException("Number must be between 1 and 50");
                String T = "";
                for (int i = 1; i <= 10; i++)
                    T += n + " x " + i + " = " + (n * i) + "\n";
                tA.setText(T);
            } catch (NumberFormatException ex) {
                tA.setText("Invalid input. Please enter a valid number.");
            }
        });

        P.add(new JLabel("Enter a number (1-50):"));
        P.add(tF);
        P.add(B);
        P.add(new JScrollPane(tA));

        F.add(P);
        F.pack();
        F.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Applet::new);
    }
}
