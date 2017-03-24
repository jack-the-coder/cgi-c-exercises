//
//  main.c
//  cgi-c-exercises
//
//  Created by jack-the-coder on 3/24/17.
//  Copyright © 2017 jack-the-coder. All rights reserved.
//

// Compilation worked on GCC and Xcode. Requires GET requests, reads from QUERY_STRING environment variable

// MODIFIED FROM: https://www.cs.tut.fi/~jkorpela/forms/cgic.html

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char *data;
    long m,n;
    printf("%s%c%c\n",
           "Content-Type:text/html;charset=iso-8859-1",13,10);
    printf("<title>Results</title>\n");
    printf("<h3>Results</h3>\n");
    printf("<p>The multiplication problem you requested has been run and below are the results of it: </p>");
    data = getenv("QUERY_STRING");
    if(data == NULL)
        printf("<p>Error! Error in passing data from form to script.</p>");
    else if(sscanf(data,"m=%ld&n=%ld",&m,&n)!=2)
        printf("<p>Error! Invalid data. Data must be numeric.</p>");
    else
        printf("<p>The product of %ld and %ld is %ld.</p>",m,n,m*n);
    return 0;
}
