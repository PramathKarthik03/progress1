#include<iostream>
#include<string.h>
using namespace std;


  struct song   //node creation.
            {
                string name;
                string artist;
                string genre;
                double length;
                struct song *next;
                struct song *prev;
            }*start,*last;

    int counter =0;

class Songplayer    //class declaration.
{
    public:
            Songplayer()    //constructor
            {
                start = NULL;            //points to the head of the play list.

                last = NULL;         /*points to the node that is being played
                                        and gets updated as new songs are played/deleted*/

            }

            song *create_song(string,string,string,double );//new song is created and initializes contents.
            void insert_begin();
};
//main function
int main()

{

    int choice;

    Songplayer s;//obj


    while (1)

    {

        cout<<"\n-------------------------------"<<endl;

        cout<<"Implementation of Music Play list "<<endl;

        cout<<"\n-------------------------------"<<endl;

        cout<<"1.Insert the song at the Beginning"<<endl;

        cout<<"2.Insert the song at the Last"<<endl;

        cout<<"3.Insert the song at desired Position"<<endl;

        cout<<"4.Delete the song at the Beginning"<<endl;

        cout<<"5.Delete the song at the Last"<<endl;

        cout<<"6.Delete the song at the desired Position"<<endl;

        cout<<"7.Search song"<<endl;

        cout<<"8.Delete the searched song"<<endl;

        cout<<"9.Sort the PlayList"<<endl;

        cout<<"10.Display the current song"<<endl;

        cout<<"11.Display the previous song"<<endl;

        cout<<"12.Display the songs of that Genre"<<endl;

        cout<<"13.Display the PlayList"<<endl;

        cout<<"14.Reverse the PlayList"<<endl;

        cout<<"15.Exit"<<endl;



        cout<<"Enter your choice : ";

        cin>>choice;

        switch(choice)

        {

        case 1:

            s.insert_begin();

            break;



        default:

            cout<<"Wrong choice"<<endl;

        }

    }

    return 0;

}

song* Songplayer::create_song(string sname,string sartist,string sgenre,double slength)
{

    counter++;

    struct song *temp;

    temp = new(struct song);

    temp->name = sname;
    temp->artist = sartist;
    temp->genre = sgenre;
    temp->length = slength;

    temp->next = NULL;
    temp->prev = NULL;

    return temp;

}

void Songplayer::insert_begin()

{

    string name,artist,genre;
    double length;

    cout<<endl<<"Enter the song name,artist,genre and length\n";
        cin>>name>>artist>>genre>>length;

    struct song *temp;
    temp = create_song(name,artist,genre,length);

    if (start == last && start == NULL)
    {

        start = last = temp;

        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
        cout<<"song is successfully inserted"<<endl;
        cout<<endl;
    }

    else

    {

        temp->next = start;
        start->prev = temp;

        start = temp;

        start->prev = last;
        last->next = start;

        cout<<"song is successfully inserted"<<endl;
        cout<<endl;
    }

}
