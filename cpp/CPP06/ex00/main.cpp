/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:44:42 by ecamara           #+#    #+#             */
/*   Updated: 2022/12/22 18:23:50 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Void.hpp"

typedef struct s_values
{
    char c;
    int num;
    float numff;
    double numf;
    int checkC;
    int checknum;
    int checknumff;
    int checknumf;
}t_values;
/*
void    convert(char *str, t_values *values)
{
    std::string input(str);

    if (str[0] > 33)
        values->checkC = 1;
    else
        values->checkC = 0;
    values->c = str[0];
    values->num = str[0];
    values->numff = str[0];
    values->numf = str[0];
}*/


void display(t_values values)
{
    std::cout << "char: ";
    if (values.checkC == 1)
        std::cout << values.c << std::endl;
    else if (!values.checkC)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "Imposible" << std::endl;
    std::cout << "int: " << values.num << std::endl << "float: " << values.numf << ".f" << std::endl << "double: " << values.numff  << std::endl;
}

int main(int argc, char *argv[])
{
    Void values;
    if (argc != 2)
        return (1);
    std::cout << argv[1] << std::endl;
    values.assign(argv[1]);
    values.checkType(argv[1]);
    return (0);
}

/*
import java.util.Scanner;
import java.util.Random;

class Game
{
    int wins;
    int games;
    int tryes;
    int best;
    public Game()
    {
        wins = 0;
        games = 0;
        tryes = 0;
        best = -1;
    }
}

public class MyClass {
    public static void main(String args[]) {
      Game game = new Game();
      System.out.println("intro");
      play(game);
    }
    
    static void play(Game game)
    {
        int check = 1;
        int index = 1;
        int num;
        Random random = new Random();
        Scanner scanner = new Scanner(System.in);
        int numToGuess = random.nextInt(100) + 1;
        System.out.println(numToGuess);
        do
        {
            System.out.println("introduce number: ");
            num = scanner.nextInt();
            game.tryes++;
            if (checkNum(num, numToGuess))
            {
                if (index < game.best || game.best == -1)
                    game.best = index;
                game.wins++;
                check = 0;
            }
            index++;
        }while (index <= 10 && check == 1);
        game.games++;
        statistics(game);
        if (yesNoQuestion(scanner))
            play(game);
    }
    
    static boolean checkNum(int num, int numToGuess)
    {
        if (num == numToGuess)
            return (true);
        else if (num < numToGuess)
            System.out.println("Number is higher\n");
        else
           System.out.println("Number is lower\n");
        return (false);
    }
    
    static boolean yesNoQuestion(Scanner scanner)
    {
        System.out.println("Play again?(Si)(No)");
        char ans = scanner.next().charAt(0);
        if (ans == 'S' || ans == 's')
            return (true);
        return (false);
    }
    
    static void statistics(Game game)
    {
        System.out.println("*************************\n");
        System.out.println("Games = " + game.games);
        System.out.println("Wins = " + game.wins);
        System.out.println("Tryes = " + game.tryes);
        System.out.println("Best = " + game.best);
        System.out.println("*************************\n");
    }
}*/