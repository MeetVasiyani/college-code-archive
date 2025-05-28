/*75. Write a program to simulate music player application using suitable data 
structure. There is no estimation about number of music files to be managed by 
the music player. Your program should support all the basic music player 
operations to play and manage the playlist.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Song {
    char title[100];
    struct Song* next;
    struct Song* prev;
} Song;

Song* head = NULL;
Song* current = NULL;

Song* createSong(char* title) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    newSong->next = newSong->prev = NULL;
    return newSong;
}

void addSong(char* title) {
    Song* newSong = createSong(title);
    if (head == NULL) {
        head = newSong;
        current = head;
    } else {
        Song* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newSong;
        newSong->prev = temp;
    }
    printf("Song \"%s\" added to playlist.\n", title);
}

void deleteSong(char* title) {
    Song* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            if (temp == head)
                head = temp->next;
            if (temp->prev)
                temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            if (temp == current)
                current = head;
            free(temp);
            printf("Song \"%s\" deleted.\n", title);
            return;
        }
        temp = temp->next;
    }
    printf("Song \"%s\" not found.\n", title);
}

void playCurrent() {
    if (current)
        printf("Now playing: %s\n", current->title);
    else
        printf("No song in playlist.\n");
}

void playNext() {
    if (current && current->next) {
        current = current->next;
        playCurrent();
    } else {
        printf("This is the last song or playlist is empty.\n");
    }
}

void playPrevious() {
    if (current && current->prev) {
        current = current->prev;
        playCurrent();
    } else {
        printf("This is the first song or playlist is empty.\n");
    }
}

void displayPlaylist() {
    Song* temp = head;
    int index = 1;
    if (temp == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    printf("Playlist:\n");
    while (temp != NULL) {
        printf("%d. %s", index++, temp->title);
        if (temp == current) printf(" <-- Now Playing");
        printf("\n");
        temp = temp->next;
    }
}

void main(){
    int choice;
    char title[100];
    while (1) {
        printf("\nMusic Player Menu:\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Play Current Song\n");
        printf("4. Play Next Song\n");
        printf("5. Play Previous Song\n");
        printf("6. Display Playlist\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter song title to add: ");
                scanf(" %[^\n]", title);
                addSong(title);
                break;
            case 2:
                printf("Enter song title to delete: ");
                scanf(" %[^\n]", title);
                deleteSong(title);
                break;
            case 3:
                playCurrent();
                break;
            case 4:
                playNext();
                break;
            case 5:
                playPrevious();
                break;
            case 6:
                displayPlaylist();
                break;
            case 7:
                break;
            default:
                printf("Invalid choice.\n");
        }
        if (choice == 7)
            break;
    
    }
}