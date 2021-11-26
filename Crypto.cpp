#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <list>

using namespace std;

int ggd(int WaardeA, int WaardeB)//ggd bereken

{
    //WaardeA is de hoogste
    //WaardeB is de laagste
    int restwaarde; //restwaarde na deling
    int delingwaarde; //getal waardoor geddeld wordt
    int antwoord;
    
    if (WaardeA<=WaardeB) { return -1;} //Als WaardeA niet de hoogste is kan er geen berekening plaatvinden
    else 
    {
        restwaarde = 1;
        while (restwaarde !=  0)
        {
            restwaarde = WaardeA % WaardeB; //A mod B
            delingwaarde = (int)round(WaardeA/WaardeB); //Hoeveel keer kun je A/B doen
            WaardeA=WaardeB; //A wordt B
            if (restwaarde!=0) {antwoord=restwaarde;} //Als restwaarde = 0 dan GGD gevinden
            WaardeB=restwaarde; // B wordt de restwaarde
        }
        return WaardeA; //GGD      
    }

}

void testggd() //place holder for ggd test code
{
    int Nummer1;
    int Nummer2;
    cout << "WaardeA=";cin >> Nummer1; cout<<endl;
    cout << "WaardeB=";cin >> Nummer2; cout<<endl;
    cout << "GGD=" << ggd(Nummer1,Nummer2) << endl;
}

list<int> Delers(int WaardeA)
{
    list<int> lijst;
    for (int i = 1; i <= (int)(WaardeA/2); i++) //Zoeken naar delers tot de  A. 
    {
        if ( WaardeA % i == 0 )
        {
            lijst.push_back(i);
        }
        
    }
    lijst.push_back(WaardeA);
    return lijst;
}

bool priem(int WaardeA)
{
    list<int> Deler; //var om de delers in op te slaan
    Deler=Delers(WaardeA); //aantal delers bepalen
    if (Deler.size()==2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    list<int> Test;
    int input;
    cin>>input;
    Test=Delers(input);
    for (list<int>::iterator it =Test.begin(); it !=Test.end(); it++)
    {
        cout << *it << ' ';
    }
    cout<<endl<<"lijs grote is "<<Test.size();
    cout<<boolalpha;
    cout<<"Het getal is een priem:"<<priem(input)<<endl<<endl;

    return 0;   
}