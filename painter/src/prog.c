/* ALLEGRO */
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>

/* std */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ----------------------------------------------------------------------- */

typedef int i32_t;
typedef unsigned char* u8_t;
typedef u8_t pbyte;
typedef unsigned char byte;
typedef unsigned int u32_t;
typedef unsigned short u16_t;
typedef i32_t dword_t;
typedef char char_t;
typedef void void_t;

/* ----------------------------------------------------------------------- */

enum _boolean {
    FALSE=0,
    TRUE=1
};
typedef enum _boolean bool_t;

enum pode_se {
    NO=0,
    YES=1
};

/* ----------------------------------------------------------------------- */

struct bitmap_t {
    const char_t *nome;
    dword_t size;
};

struct file_io_t {
    FILE *arq;
    const char_t *filename;
};

struct color_t {
    u8_t color;
    u8_t g;
    u8_t r;
    u8_t b;
    u8_t a;
};

struct pen_t {
    struct color_t *pen_color;
    dword_t size;
};

struct allegro_sis {
    ALLEGRO_COLOR al_color;                    
    ALLEGRO_MOUSE_STATE al_mouse_state;
    ALLEGRO_KEYBOARD_STATE al_keyboard_state;  
    ALLEGRO_DISPLAY *al_display;        
    ALLEGRO_DISPLAY *al_fileio;         
    ALLEGRO_EVENT_QUEUE *al_queue;             
    ALLEGRO_EVENT al_event;                    
    ALLEGRO_TEXTLOG *al_textlog;        
    ALLEGRO_FILECHOOSER *al_savefile;          
    int int_mode;        /* 0 */                   
    float thickness;     /* thickness */              
    bool_t mouse_over;   /* 1 */ 
};

struct al_bitmap {
    ALLEGRO_BITMAP *bitmap;
    struct al_bitmap *prox;
    struct al_bitmap *antes;
    ALLEGRO_BITMAP *buffer;
};

/* ----------------------------------------------------------------------- */

struct file_io_t write_file(struct file_io_t *file);
struct file_io_t read_file(struct file_io_t read);
void_t get_file_procedure(FILE *fp, const char_t* unname);
struct color_t get_color(struct color_t *ucolor);
void_t put_icon_position(struct bitmap_t *bitmap);
void_t draw_components();
dword_t get_more_less(dword_t size);

void_t add_revision_function();
void_t cizx_toolbox_function();
void_t pencil_function();
void_t triangle_function();
void_t line_function();
void_t rectangle_function();
void_t spray_function();
void_t circle_function();
void_t save_bitmap_function();
void_t open_bitmap_function();
void_t undo_function();
void_t redo_function();
dword_t init_allegro5(struct allegro_sis *al);

dword_t tam_keyboard_arrow(struct pen_t *pen, dword_t size);

/* ----------------------------------------------------------------------- */

#define SIZE                    24
#define SIZE_A                  SIZE * 1.4
#define MARGIN                  2
#define MARGIN_A                ((2 * SIZE + 3 * MARGIN) - SIZE*1.4) /2
#define PROGRAM_SUCCESS         0
#define width                   1000
#define height                  600
#define PHIA                    .618
#define _thickness               6
#define FAIL                    -1

/* ----------------------------------------------------------------------- */

struct file_io_t write_file(struct file_io_t *file)
{
    /* Sem implementação ainda */
    return *file;
}

struct file_io_t read_file(struct file_io_t read)
{
    /* Sem implementação ainda */
    return read;
}

void_t get_file_procedure(FILE *fp, const char_t* unname)
/*  
 * Sem implementação ainda 
 * Atribuição para as rotinas de read e write
 */ 
{ }

struct color_t get_color(struct color_t *ucolor)
{   ucolor = 
    (struct color_t *)malloc(sizeof(struct color_t *);
    ucolor->r = 0x000;
    ucolor->g = 0x000;
    ucolor->b = 0x000;
    return *ucolor;
}

dword_t init_allegro5(struct allegro_sis *al)
{   struct al_bitmap *image;
    struct al_bitmap *revista;
    
    if(!al_init()) {
        fprintf(stderr, "errors ao init allegro!\n");
        return FAIL;
    }
    if(!al_init_native_dialog_addon()) {
        fprintf(stderr, "errors ao init allegro native\n");
        return FAIL;
    }
    if(!al_install_mouse()) {
        fprintf(stderr, "errors ao init mouse\n");
        return FAIL;
    }
    if(!al_install_keyboard()) {
        fprintf(stderr, "errors ao init keyboard\n");
        return FAIL;
    }
    if(!al_init_primitives_addon()) {
        fprintf(stderr, "errors ao init primitives\n");
        return FAIL;
    }
    if(!al_init_image_addon()) {
        fprintf(stderr, "errors ao init image\n");
        return FAIL;
    }
    
    al->al_color = al_map_rgb(255,255,255);
    al->al_display = al_create_display(width, height + 2 * (SIZE) + 3 * MARGIN);
    
    al_set_window_title(al->al_display, "Painter 68, C");
    image->bitmap = al_load_bitmap("png/artist.png");
    
    al_set_display_icon(al->al_display, image->bitmap);
    al_destroy_bitmap(image->bitmap);
    
    if(!al->al_display) {
        fprintf(stderr, "Errors to create display!\n");
        return FAIL;
    }
    
    revista = (struct al_bitmap *) malloc(sizeof(struct al_bitmap *));
    revista->buffer = al_clone_bitmap(al_get_backbuffer(al->al_display));
}

void_t put_icon_position(struct bitmap_t *bitmap)
{ bitmap->size = SIZE; }

void_t draw_components()
{ /* Sem impl */ }

dword_t get_more_less(dword_t size)
/* \RETURN: Keyboard + ou - */
{}

void_t add_revision_function()
{}

void_t cizx_toolbox_function()
{}

void_t pencil_function()
{}

void_t triangle_function()
{}

void_t line_function()
{}

void_t rectangle_function()
{}

void_t spray_function()
{}

void_t circle_function()
{}

void_t save_bitmap_function()
{}

void_t open_bitmap_function()
{}

void_t undo_function()
{}

void_t redo_function()
{}

dword_t tam_keyboard_arrow(struct pen_t *pen, dword_t size)
{
    return size;
}

/* ----------------------------------------------------------------------- */

int main(void) {
    return PROGRAM_SUCCESS;
}
