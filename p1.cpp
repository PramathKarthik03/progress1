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
            }*head,*current;

    int counter =0;

class Songplayer    //class declaration.
{
    public:
            Songplayer()    //constructor
            {
                head = NULL;            //points to the head of the play list.

                current = NULL;         /*points to the node that is being played
                                        and gets updated as new songs are played/deleted*/

            }

            void add_song(string,string,string,double );//new song is created and initializes contents.
            void play_song(string);//displays the  song and its info when its name matches with the given input.
            void play_current_song();//displays the song that the current pointer is pointing.
            void play_next_song();//the current pointer points to next song and and display its details.
            void play_previous_song();//the current pointer points to the previous song and displays its details.
            void delete_song(string);//searches for the song which is taken as input and deletes if match is found.
            void delete_current_song();//deletes the song the current pointer is pointing.
            void play_all(string);//displays all the songs of that specific genre.
            void playlist();//displays all the songs.
            void reverse_playlist();//displays all the song in reverse order.
            void sorting();//sorts the songs.
};
