#include <iostream>
#include <ctime>
 
void PrintIntroduction(int diff)
{
    std::cout << "You are a secret agent breaking in to a level "<< diff;
    std::cout << " secure server room..\n";
    std::cout<<"Enter the correct code to continue\n";
}

bool PlayGame(int diff)
{
    PrintIntroduction(diff);
    
    const int CodeA= rand()%diff +1;
    const int CodeB= rand()%diff +1;
    const int CodeC= rand()%diff +1;
    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    std::cout << "There are 3 numbers in the code"<<std::endl;
    std::cout << "The code adds up to : "<<CodeSum << std::endl;
    std::cout << "The code multiply to give : "<<CodeProduct <<std::endl;

    int GuessA,GuessB,GuessC;
    std::cout<< "enter your guess: ";
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: "<< GuessA<<GuessB<<GuessC<<std::endl;

    int GuessSum = GuessA+GuessB+GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout<<"you win!\n";
        std::cout<<"well done agent! you have extracted a file...keep going..\n";
        return true;
    }
    else
    {
        std::cout<<"you lose!\n";
        std::cout<<"you entered a wrong code! try again...\n";
        return false;
    }

}

int main()
{
    srand(time(NULL));
    int levelDifficulty=1;
    const int maxlevel=3;
    while(levelDifficulty<=maxlevel)
    {
        bool levelComplete = PlayGame(levelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if(levelComplete)
        {
            //inc level difficulty 
            ++levelDifficulty;

        }
    }
   
    std::cout << "\n\n Great work agent ! you have completed all levels !\n";
    return 0;
}