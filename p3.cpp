#include<iostream>
#include<string.h>
#include<cstdlib>
#include<cstdio>
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
            void insert_begin();    //add song in the beginning.
            void insert_last();     //add song in the end.
            void insert_pos();      //add song at desired position.
            void delete_pos();      //delete song at desired position.
            void search();          //search for a song.
            void del_search();      //search the song and delete.
            void sort1();            //sort
            void display();
            void reverse();
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

        cout<<"4.Delete the song at the desired Position"<<endl;

        cout<<"5.Search song"<<endl;

        cout<<"6.Delete the searched song"<<endl;

        cout<<"7.Sort the PlayList"<<endl;

        cout<<"8.Display the PlayList"<<endl;

        cout<<"9.Reverse the PlayList"<<endl;

        cout<<"10.Exit"<<endl;



        cout<<"Enter your choice : ";

        cin>>choice;

        switch(choice)

        {

        case 1:

            s.insert_begin();
            break;


        case 2:

            s.insert_last();
            break;

        case 3:

            s.insert_pos();
            break;

        case 4:

            s.delete_pos();
            break;

        case 5:

            s.search();
            break;

        case 6:

            s.del_search();
            break;

        /*case 7:

            s.sort1();
            break;*/

        case 8:

            s.display();
            break;

        case 9:

            s.reverse();
            break;

        case 10:

            exit(1);

        default:

            cout<<"Wrong choice"<<endl;

        }

    }

    return 0;

}

song* Songplayer::create_song(string sname,string sartist,string sgenre,double slength)     /*create a node called song
                                                                                              which has song and its
                                                                                                details dynamically.*/
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

void Songplayer::insert_begin()                                                 //insert the song at the beginning.

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
        cout<<"song is successfully inserted in an empty list"<<endl;
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



void Songplayer::insert_last()                                                     //insert the song in the last

{

    string name,artist,genre;
    double length;

    cout<<endl<<"Enter the song name,artist,genre and length"<<endl;
        cin>>name>>artist>>genre>>length;

    struct song *temp;

    temp = create_song(name,artist,genre,length);

    if (start == last && start == NULL)

    {

        start = last = temp;

        start->next = last->next = NULL;
        start->prev = last->prev = NULL;

        cout<<"song is successfully inserted in an empty list"<<endl;

    }

    else

    {
        last->next = temp;
        temp->prev = last;

        last = temp;

        start->prev = last;
        last->next = start;

        cout<<"song is successfully inserted"<<endl;
    }

}

void Songplayer::insert_pos()                             //insert the song at desired position.

{
    string name,artist,genre;
    double length;
    int  pos, i;

    cout<<endl<<"Enter the song name,artist,genre and length"<<endl;
        cin>>name>>artist>>genre>>length;


    cout<<endl<<"Enter the position of the song u want to insert at: ";
        cin>>pos;

    struct song *temp,*q,*ptr;

    temp = create_song(name,artist,genre,length);

    if (start == last && start == NULL)
    {
        if (pos == 1)
        {

            start = last = temp;

            start->next = last->next = NULL;
            start->prev = last->prev = NULL;

            cout<<"song is successfully inserted in an empty list"<<endl;
        }
        else
        {
            cout<<"Position out of range"<<endl;
            counter--;
            return;
        }
    }
    else
    {
        if (counter < pos)
        {
             cout<<"Position out of range"<<endl;
             counter--;
             return;
        }
        q = start;
        for (i = 1;i <= counter;i++)
        {
            ptr = q;
            q = q->next;
            if (i == pos - 1)
            {
                ptr->next = temp;
                temp->prev = ptr;
                temp->next = q;
                q->prev = temp;

                cout<<"song is successfully inserted at position "<<pos<<endl;
                break;
            }
        }
    }
}

void Songplayer::delete_pos()                                                        //deletion of song
{
    int pos, i;
    song *ptr, *s;

    if (start == last && start == NULL)
    {
        cout<<"play list does not exist "<<endl;
        return;
    }

    cout<<endl<<"Enter the position of element to be deleted: ";
        cin>>pos;

    if (counter < pos)
    {
        cout<<"Position out of range"<<endl;
        return;
    }
    s = start;

    if(pos == 1)
    {
        counter--;
        last->next = s->next;
        s->next->prev = last;

        start = s->next;
        free(s);
        cout<<"song is successfully deleted "<<endl;

        return;

    }

    for (i = 0;i < pos - 1;i++ )
    {
        s = s->next;
        ptr = s->prev;

    }
    ptr->next = s->next;
    s->next->prev = ptr;

    if (pos == counter)
    {
        last = ptr;
    }
    counter--;
    free(s);
    cout<<"song is successfully deleted"<<endl;

}


void Songplayer::search()                                       //to search for a song.
{
    int pos = 0, i;
    bool flag = false;
    struct song *s;
    string sname;

    if (start == last && start == NULL)
    {
        cout<<" the play list is not created, nothing to search "<<endl;
        return;

    }
    cout<<endl<<"Enter the song name to be searched: ";
        cin>>sname;

    s = start;
    for (i = 0;i < counter;i++)
    {
        pos++;
        if (s->name == sname)
        {
            cout<<"song "<<sname<<" found at position: "<<pos<<endl;
            flag = true;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"song is not found in the play list"<<endl;

}



void Songplayer::del_search()                                       //to search for a song.
{
    int pos = 0, i;
    bool flag = false;
    struct song *s;
    string sname;

    if (start == last && start == NULL)
    {
        cout<<" the play list is not created, nothing to search "<<endl;
        return;

    }
    cout<<endl<<"Enter the song name to be deleted: ";
        cin>>sname;

    s = start;
    for (i = 0;i < counter;i++)
    {
        pos++;
        if (s->name == sname)
        {
            cout<<"song "<<sname<<" found at position: "<<pos<<endl;
            flag = true;
            free(s);
            cout<<"  successfully deleted "<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"song is not found in the play list"<<endl;

}

/*void Songplayer::sort1()
{
    struct song *temp, *s;
    int i;
    string name;

    if (start == last && start == NULL)
    {
        cout<<"The play list is empty, nothing to sort"<<endl;
        return;
    }

    s = start;
    for (i = 0;i < counter;i++)
    {
        temp = s->next;

        while (temp != start)
        {
            if (s->name > temp->name)
            {
                name= s->name;
                s->name = temp->name;
                temp->name = name;
            }
            temp = temp->next;
        }
        s = s->next;
    }
}*/


void  Songplayer::display()
{
    int i;
    struct song *s;

    if (start == last && start == NULL)
    {
        cout<<"The play list is empty, nothing to display"<<endl;
        return;
    }

    s = start;

    for (i = 0;i < counter-1;i++)
    {
        cout<<s->name<<endl<<s->artist<<endl<<s->genre<<endl<<s->length<<endl<<"<----------->"<<endl;;
        s = s->next;
    }
    cout<<s->name<<endl<<s->artist<<endl<<s->genre<<endl<<s->length<<endl;

}

void Songplayer::reverse()
{
    if (start == last && start == NULL)
    {
        cout<<"The play list is empty, nothing to reverse"<<endl;
        return;
    }
    struct song *p1, *p2;

    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;

    while (p2 != start)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }

    last = start;
    start = p1;

    cout<<"play list is reversed successfully"<<endl;

}

