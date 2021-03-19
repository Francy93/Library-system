#ifndef _LIBRARY_HXX_
#define _LIBRARY_HXX_

#include <iostream>
#include <string>   //library for string variables
#include <regex>    // regular expressions
#include <fstream>  // file text scanner
#include <vector>   // vectors library
#include <deque>    // deque library


class Global{

    public:
        //string to lower case
        std::string toLower(std::string s);
        //to string
        long sToll(std::string s);

        //this is a string printer printer
        template <typename... Ts>
        void println(Ts const & ... vals){
            using unused = int[];
            std::vector<std::string> args;
            (void)unused { 0, (args.push_back(vals), 0)... };

            std::string start = "";
            std::string end = "";

            if(args.size() > 1){
                std::string colors [] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};
                for (unsigned int i=0; i< sizeof(colors)/sizeof(*colors); i++){
                    if(toLower(args[args.size()-1]) == colors[i]){
                        start = "\033[1;3"+std::to_string(i)+"m";
                        end = "\033[0m";
                    }
                }
            }

            std::string print = "";
            unsigned int size = start == ""? args.size(): args.size()-1;
            for(unsigned int i=0; i< size; i++){
                print +=args[i];
            }
            
            std::cout << start+print+end << std::endl;
        }

        //the holly strings splitter
        std::vector<std::string> split(std::string s, std::string delim);
        //an enanched and actually workin cin
        std::string cinln();
        //table generator
        std::string tableMaker(std::deque<std::deque<std::string>> allData, std::vector<unsigned int> longest);
};


class Books: public Global {

    private:
        std::string title;
        std::string author;
        unsigned long long isbn;
        unsigned int qty;

    public:
        //Books constructor
        Books(std::string t, std::string a, std::string i, std::string q);
        ~Books();

        std::string getTitle();
        std::string getAuthor();
        unsigned long long getId();
        unsigned int getQty();
        // modifing book quantity attribute
        unsigned int modifyQty(int qty, bool mode);
        //checking wether a book is empty or not
        bool emptyCheck();
        //printing book values
        std::string bookPrint();
        //book dashboard
        int bookManager();
};
        


class Collection: public Global {

    protected: 
        std::deque<Books> data;

    public:
        //erasing book collection
        void collectionClear();
        //remove a book
        void removeBook(int index);
        //add a book
        void addBook(Books book);
        //get a book
        Books getBook(int index);
                
        //seartching algorithm
        std::deque<Books> searchEngine(std::string title);
        //find a book
        int findBook();
        //adding a new book
        int addNewBook();
        //building booksTable
        std::string booksTable(std::deque<Books> books);
        //print all books
        void printCollection();
        //select book from table
        int booksChoice(std::deque<Books> books);
        //quick-sort
        void quicksort(std::deque<Books>& arr, int left, int right);
};



class Operations: public Collection{

    public:
        Operations(){};
        ~Operations(){};

        //file reader
        int reader(std::string fileName);
        //main menu
        int options();
};


#endif