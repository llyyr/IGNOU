class Matrix {
    private int[][] M;
    private int R, C;

    public Matrix(int R, int C) {
        this.R = R;
        this.C = C;
        this.M = new int[R][C];
    }

    public void add(Matrix m) {
        if (this.R != m.R || this.C != m.C) {
            System.out.println("Dimensions do not match.");
            return;
        }

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                this.M[i][j] += m.M[i][j];
    }

    public void display() {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++)
                System.out.print(this.M[i][j] + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Matrix M1 = new Matrix(2, 2);
        Matrix M2 = new Matrix(2, 2);

        M1.M[0][0] = 1;
        M1.M[0][1] = 2;
        M1.M[1][0] = 3;
        M1.M[1][1] = 4;

        M2.M[0][0] = 5;
        M2.M[0][1] = 6;
        M2.M[1][0] = 7;
        M2.M[1][1] = 8;

        System.out.println("Matrix 1:");
        M1.display();

        System.out.println("Matrix 2:");
        M2.display();

        System.out.println("Sum of matrices:");
        M1.add(M2);
        M1.display();
    }
}
