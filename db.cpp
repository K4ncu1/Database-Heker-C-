#include <iostream>
#include <string>
#include <fstream>

class Heker {
    public:
        std::string nick;
        std::string marga;
        std::string tim;

        Heker (std::string nick, std::string marga, std::string tim){
            Heker::nick = nick;
            Heker::marga = marga;
            Heker::tim = tim;
        }

        std::string stringify (){
            return "\n" + nick + " " + marga + " " + tim;
        }

};

class DBase {
    public:
        std::ifstream in;
        std::ofstream out;
        std::string fileName;

        DBase (const char* fileName){
            DBase::fileName = fileName;
        }

        void save (Heker data){
            std::cout << data.nick << std::endl;
            std::cout << data.marga << std::endl;
            std::cout << data.tim << std::endl;

            DBase::out.open(DBase::fileName, std::ios::app);
            DBase::out << data.stringify();
            DBase::out.close();
        }

        void showAll (){
            DBase::in.open(DBase::fileName, std::ios::in);
            std::string nick, marga, tim;
            int index = 1;

            while (!DBase::in.eof())
            {
                DBase::in >> nick;
                DBase::in >> marga;
                DBase::in >> tim;

                std::cout << index++ << ".\t";
                std::cout << nick << "\t";
                std::cout << marga << "\t";
                std::cout << tim << std::endl;
            }
            DBase::in.close();
        }

};

int main(int argc, char const *argv[])
{ 
    DBase database = DBase ("data.txt");

    database.showAll ();


    std::string nick, marga, tim;
    std::cout << "MASUKAN DATA HEKER" << std::endl;
    std::cout << "Nick  : ";
    std::cin >> nick;
    std::cout << "Marga : ";
    std::cin >> marga;
    std::cout << "Tim : ";
    std::cin >> tim;

    Heker dataHeker = Heker (nick, marga, tim);

    database.save (dataHeker);

    database.showAll ();
    
    return 0;
}
