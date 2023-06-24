
// Gnl exam version?

#ifndef GET_NEXT_LINE_H 
 # define GET_NEXT_LINE_H 
  
 # include <unistd.h> 
 # include <stdlib.h> 
  
 # ifndef BUFFER_SIZE 
 #  define BUFFER_SIZE 42 
 # endif 
  
 char        *get_next_line(int fd); 
  
 #endif

…

#include "get_next_line.h" 
  
 char *get_next_line(int fd) 
 { 
     int     i = 0; 
     int     rd = 0; 
     char    character; 
     char     *buffer = malloc(10000); 
  
     if (BUFFER_SIZE <= 0) 
         return (free(buffer), NULL); 
     while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0) 
     { 
         buffer[i++] = character; 
         if (character == '\n') 
             break; 
     } 
     if ((!buffer[i - 1] && !rd) || rd == -1) 
     { 
         free(buffer); 
         return (NULL); 
     } 
     buffer[i] =  '\0'; 
     return(buffer); 
 }

