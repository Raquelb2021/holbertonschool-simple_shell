#include "shellheader.h"
/**
 *
 *
 */
char *shell_read_line()
{
	    char *line = NULL;
	        size_t buflen = 0;

	         getline(&line, &buflen, stdin);

	        return (line);
}
