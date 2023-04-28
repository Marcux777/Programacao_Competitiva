package Beecrowd.Resolvidos;
import java.io.IOException;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws IOException {

    
        Scanner sc = new Scanner(System.in);

        double n, nota;
        int moeda;
    
        n = sc.nextDouble();

        // NOTAS
        System.out.println("NOTAS:");
        nota = (int) n / 100;
        System.out.printf("%.0f nota(s) de R$ 100.00\n", nota);
        nota = (int) n % 100 / 50;
        System.out.printf("%.0f nota(s) de R$ 50.00\n", nota);
        nota = (int) n % 100 % 50 / 20;
        System.out.printf("%.0f nota(s) de R$ 20.00\n", nota);
        nota = (int) n % 100 % 50 % 20 / 10;
        System.out.printf("%.0f nota(s) de R$ 10.00\n", nota);
        nota = (int) n % 100 % 50 % 20 % 10 / 5;
        System.out.printf("%.0f nota(s) de R$ 5.00\n", nota);
        nota = (int) n % 100 % 50 % 20 % 10 % 5 / 2;
        System.out.printf("%.0f nota(s) de R$ 2.00\n", nota);

        // MOEDAS
        moeda = (int) (n * 100);
        System.out.println("MOEDAS:");
        nota = moeda % 10000 % 5000 % 2000 % 1000 % 500 % 200 / 100;
        System.out.printf("%.0f moeda(s) de R$ 1.00\n", nota);
        nota = moeda % 10000 % 5000 % 2000 % 1000 % 500 % 200 % 100 / 50;
        System.out.printf("%.0f moeda(s) de R$ 0.50\n", nota);
        nota = moeda % 10000 % 5000 % 2000 % 1000 % 500 % 200 % 100 % 50 / 25;
        System.out.printf("%.0f moeda(s) de R$ 0.25\n", nota);
        nota = moeda % 10000 % 5000 % 2000 % 1000 % 500 % 200 % 100 % 50 % 25 / 10;
        System.out.printf("%.0f moeda(s) de R$ 0.10\n", nota);
        nota = moeda % 10000 % 5000 % 2000 % 1000 % 500 % 200 % 100 % 50 % 25 % 10 / 5;
        System.out.printf("%.0f moeda(s) de R$ 0.05\n", nota);
        nota = moeda % 10000 % 5000 % 2000 % 1000 % 500 % 200 % 100 % 50 % 25 % 10 % 5 / 1;
        System.out.printf("%.0f moeda(s) de R$ 0.01\n", nota);

        sc.close();
    }
 
}