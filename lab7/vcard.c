#include "adrbook.h"

//const char *_vcard_todo_format = "TODO [vcard]: %s\nhalting\n";

/* vcard_new : allocate a new vcard, copy all strings, return new object
 * note: this is a "deep copy" as opposed to a "shallow copy"; the string
 * arguments are not to be shared by the newly allocated vcard
 */
vcard *vcard_new(char *cnet, char *email, char *fname, char *lname, char *tel)
{
    vcard* new_vcard = (vcard*)malloc(sizeof(vcard));
    if (new_vcard == NULL) {
        fprintf(stderr,"vcard_new: malloc failed");
        exit(1);
    } else {
        new_vcard->cnet = strdup(cnet);
        new_vcard->email = strdup(email);
        new_vcard->fname = strdup(fname);
        new_vcard->lname = strdup(lname);
        new_vcard->tel = strdup(tel);
    }
    return new_vcard;
}

/* vcard_free : free vcard and the strings it points to */
void vcard_free(vcard *c)
{
    free(c->cnet);
    free(c->email);
    free(c->fname);
    free(c->lname);
    free(c->tel);
    free(c);
}

/* vcard_show: display vcard to stdout
 */
void vcard_show(FILE *f, vcard *c)
{
    if (c == NULL) {
        fprintf(stderr, "vcard_show: cannot print empty vcard");
        exit(1);
    }
    fprintf(f, "VCARD COMPONENTS\n CNet: %s\n", c->cnet);
    fprintf(f, "email: %s\n first name: %s\n", c->email, c->fname);
    fprintf(f, "last name: %s\n telephone: %s\n", c->lname, c->tel);
}
