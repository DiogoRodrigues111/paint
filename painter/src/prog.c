/* ============================================================
 * Esse programa não foi totalmente escrito do zero.
 * Algumas sequencias de codigo foram tiradas do github
 * E algumas mais da internet.
 * 
 * Mais foi tudo re-escrito do zero, com o auxilio da internet
 * para poder se ambientar.
 * 
 * Autor: Diogo Roessler - 2020
 ============================================================ */


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
    YES=1,
    PODE=2,
    PODE_SE=3
};

enum keyboard_t
{
   KEYBOARD_EVENT_JOYSTICK_AXIS               =  1,
   KEYBOARD_EVENT_JOYSTICK_BUTTON_DOWN        =  2,
   KEYBOARD_EVENT_JOYSTICK_BUTTON_UP          =  3,
   KEYBOARD_EVENT_JOYSTICK_CONFIGURATION      =  4,

   KEYBOARD_EVENT_KEY_DOWN                    = 10,
   KEYBOARD_EVENT_KEY_CHAR                    = 11,
   KEYBOARD_EVENT_KEY_UP                      = 12,

   KEYBOARD_EVENT_MOUSE_AXES                  = 20,
   KEYBOARD_EVENT_MOUSE_BUTTON_DOWN           = 21,
   KEYBOARD_EVENT_MOUSE_BUTTON_UP             = 22,
   KEYBOARD_EVENT_MOUSE_ENTER_DISPLAY         = 23,
   KEYBOARD_EVENT_MOUSE_LEAVE_DISPLAY         = 24,
   KEYBOARD_EVENT_MOUSE_WARPED                = 25,

   KEYBOARD_EVENT_TIMER                       = 30,

   KEYBOARD_EVENT_DISPLAY_EXPOSE              = 40,
   KEYBOARD_EVENT_DISPLAY_RESIZE              = 41,
   KEYBOARD_EVENT_DISPLAY_CLOSE               = 42,
   KEYBOARD_EVENT_DISPLAY_LOST                = 43,
   KEYBOARD_EVENT_DISPLAY_FOUND               = 44,
   KEYBOARD_EVENT_DISPLAY_SWITCH_IN           = 45,
   KEYBOARD_EVENT_DISPLAY_SWITCH_OUT          = 46,
   KEYBOARD_EVENT_DISPLAY_ORIENTATION         = 47,
   KEYBOARD_EVENT_DISPLAY_HALT_DRAWING        = 48,
   KEYBOARD_EVENT_DISPLAY_RESUME_DRAWING      = 49,

   KEYBOARD_EVENT_TOUCH_BEGIN                 = 50,
   KEYBOARD_EVENT_TOUCH_END                   = 51,
   KEYBOARD_EVENT_TOUCH_MOVE                  = 52,
   KEYBOARD_EVENT_TOUCH_CANCEL                = 53,
   
   KEYBOARD_EVENT_DISPLAY_CONNECTED           = 60,
   KEYBOARD_EVENT_DISPLAY_DISCONNECTED        = 61
};

enum key_t
{
   KEY_KEY_A		    = 1,
   KEY_KEY_B		    = 2,
   KEY_KEY_C		    = 3,
   KEY_KEY_D		    = 4,
   KEY_KEY_E		    = 5,
   KEY_KEY_F		    = 6,
   KEY_KEY_G		    = 7,
   KEY_KEY_H		    = 8,
   KEY_KEY_I		    = 9,
   KEY_KEY_J		    = 10,
   KEY_KEY_K		    = 11,
   KEY_KEY_L		    = 12,
   KEY_KEY_M		    = 13,
   KEY_KEY_N		    = 14,
   KEY_KEY_O		    = 15,
   KEY_KEY_P		    = 16,
   KEY_KEY_Q		    = 17,
   KEY_KEY_R		    = 18,
   KEY_KEY_S		    = 19,
   KEY_KEY_T		    = 20,
   KEY_KEY_U		    = 21,
   KEY_KEY_V		    = 22,
   KEY_KEY_W		    = 23,
   KEY_KEY_X		    = 24,
   KEY_KEY_Y		    = 25,
   KEY_KEY_Z		    = 26,

   KEY_KEY_0		    = 27,
   KEY_KEY_1		    = 28,
   KEY_KEY_2		    = 29,
   KEY_KEY_3		    = 30,
   KEY_KEY_4		    = 31,
   KEY_KEY_5		    = 32,
   KEY_KEY_6		    = 33,
   KEY_KEY_7		    = 34,
   KEY_KEY_8		    = 35,
   KEY_KEY_9		    = 36,

   KEY_KEY_PAD_0		= 37,
   KEY_KEY_PAD_1		= 38,
   KEY_KEY_PAD_2		= 39,
   KEY_KEY_PAD_3		= 40,
   KEY_KEY_PAD_4		= 41,
   KEY_KEY_PAD_5		= 42,
   KEY_KEY_PAD_6		= 43,
   KEY_KEY_PAD_7		= 44,
   KEY_KEY_PAD_8		= 45,
   KEY_KEY_PAD_9		= 46,

   KEY_KEY_F1		    = 47,
   KEY_KEY_F2		    = 48,
   KEY_KEY_F3		    = 49,
   KEY_KEY_F4		    = 50,
   KEY_KEY_F5		    = 51,
   KEY_KEY_F6		    = 52,
   KEY_KEY_F7		    = 53,
   KEY_KEY_F8		    = 54,
   KEY_KEY_F9		    = 55,
   KEY_KEY_F10		    = 56,
   KEY_KEY_F11		    = 57,
   KEY_KEY_F12		    = 58,

   KEY_KEY_ESCAPE	    = 59,
   KEY_KEY_TILDE		= 60,
   KEY_KEY_MINUS		= 61,
   KEY_KEY_EQUALS	    = 62,
   KEY_KEY_BACKSPACE	= 63,
   KEY_KEY_TAB		    = 64,
   KEY_KEY_OPENBRACE	= 65,
   KEY_KEY_CLOSEBRACE	= 66,
   KEY_KEY_ENTER		= 67,
   KEY_KEY_SEMICOLON	= 68,
   KEY_KEY_QUOTE		= 69,
   KEY_KEY_BACKSLASH	= 70,
   KEY_KEY_BACKSLASH2	= 71,
   KEY_KEY_COMMA		= 72,
   KEY_KEY_FULLSTOP	    = 73,
   KEY_KEY_SLASH		= 74,
   KEY_KEY_SPACE		= 75,

   KEY_KEY_INSERT	    = 76,
   KEY_KEY_DELETE	    = 77,
   KEY_KEY_HOME		    = 78,
   KEY_KEY_END		    = 79,
   KEY_KEY_PGUP		    = 80,
   KEY_KEY_PGDN		    = 81,
   KEY_KEY_LEFT		    = 82,
   KEY_KEY_RIGHT	    = 83,
   KEY_KEY_UP		    = 84,
   KEY_KEY_DOWN		    = 85,

   KEY_KEY_PAD_SLASH	= 86,
   KEY_KEY_PAD_ASTERISK	= 87,
   KEY_KEY_PAD_MINUS	= 88,
   KEY_KEY_PAD_PLUS	    = 89,
   KEY_KEY_PAD_DELETE	= 90,
   KEY_KEY_PAD_ENTER	= 91,

   KEY_KEY_PRINTSCREEN	= 92,
   KEY_KEY_PAUSE		= 93,

   KEY_KEY_ABNT_C1	    = 94,
   KEY_KEY_YEN		    = 95,
   KEY_KEY_KANA		    = 96,
   KEY_KEY_CONVERT	    = 97,
   KEY_KEY_NOCONVERT	= 98,
   KEY_KEY_AT		    = 99,
   KEY_KEY_CIRCUMFLEX	= 100,
   KEY_KEY_COLON2	    = 101,
   KEY_KEY_KANJI		= 102,

   KEY_KEY_PAD_EQUALS	= 103,	/* MacOS X */
   KEY_KEY_BACKQUOTE	= 104,	/* MacOS X */
   KEY_KEY_SEMICOLON2	= 105,	/* MacOS X */
   KEY_KEY_COMMAND	    = 106,	/* MacOS X */
   
   KEY_KEY_BACK         = 107,  /* Android back key */
   KEY_KEY_VOLUME_UP    = 108,
   KEY_KEY_VOLUME_DOWN  = 109,

   /* Android game keys */
   KEY_KEY_SEARCH       = 110,
   KEY_KEY_DPAD_CENTER  = 111,
   KEY_KEY_BUTTON_X     = 112,
   KEY_KEY_BUTTON_Y     = 113,
   KEY_KEY_DPAD_UP      = 114,
   KEY_KEY_DPAD_DOWN    = 115,
   KEY_KEY_DPAD_LEFT    = 116,
   KEY_KEY_DPAD_RIGHT   = 117,
   KEY_KEY_SELECT       = 118,
   KEY_KEY_START        = 119,
   KEY_KEY_BUTTON_L1    = 120,
   KEY_KEY_BUTTON_R1    = 121,
   KEY_KEY_BUTTON_L2    = 122,
   KEY_KEY_BUTTON_R2    = 123,
   KEY_KEY_BUTTON_A     = 124,
   KEY_KEY_BUTTON_B     = 125,
   KEY_KEY_THUMBL       = 126,
   KEY_KEY_THUMBR       = 127,
   
   KEY_KEY_UNKNOWN      = 128,

   KEY_KEY_MODIFIERS	= 215,

   KEY_KEY_LSHIFT	= 215,
   KEY_KEY_RSHIFT	= 216,
   KEY_KEY_LCTRL	= 217,
   KEY_KEY_RCTRL	= 218,
   KEY_KEY_ALT		= 219,
   KEY_KEY_ALTGR	= 220,
   KEY_KEY_LWIN		= 221,
   KEY_KEY_RWIN		= 222,
   KEY_KEY_MENU		= 223,
   KEY_KEY_SCROLLLOCK = 224,
   KEY_KEY_NUMLOCK	= 225,
   KEY_KEY_CAPSLOCK	= 226,

   KEY_KEY_MAX
};



enum key_ctrl_t
{
   KEYCTRL_KEYMOD_SHIFT       = 0x00001,
   KEYCTRL_KEYMOD_CTRL        = 0x00002,
   KEYCTRL_KEYMOD_ALT         = 0x00004,
   KEYCTRL_KEYMOD_LWIN        = 0x00008,
   KEYCTRL_KEYMOD_RWIN        = 0x00010,
   KEYCTRL_KEYMOD_MENU        = 0x00020,
   KEYCTRL_KEYMOD_ALTGR       = 0x00040,
   KEYCTRL_KEYMOD_COMMAND     = 0x00080,
   KEYCTRL_KEYMOD_SCROLLLOCK  = 0x00100,
   KEYCTRL_KEYMOD_NUMLOCK     = 0x00200,
   KEYCTRL_KEYMOD_CAPSLOCK    = 0x00400,
   KEYCTRL_KEYMOD_INALTSEQ	  = 0x00800,
   KEYCTRL_KEYMOD_ACCENT1     = 0x01000,
   KEYCTRL_KEYMOD_ACCENT2     = 0x02000,
   KEYCTRL_KEYMOD_ACCENT3     = 0x04000,
   KEYCTRL_KEYMOD_ACCENT4     = 0x08000
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
    ALLEGRO_COLOR color;
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
    dword_t int_result;
};

/* ----------------------------------------------------------------------- */

struct file_io_t write_file(struct file_io_t *file);
struct file_io_t read_file(struct file_io_t read);
void_t get_file_procedure(FILE *fp, const char_t* unname);
struct color_t get_color(struct color_t *ucolor);
void_t put_icon_position(struct bitmap_t *bitmap);
void_t draw_components();
dword_t get_more_less(dword_t size);

void_t add_revision_function(struct al_bitmap *bmp);
void_t cizx_toolbox_function();
void_t pencil_function();
void_t triangle_function();
void_t line_function();
void_t rectangle_function();
void_t spray_function();
void_t circle_function();
void_t save_bitmap_function();
void_t open_bitmap_function();
void_t undo_function(struct al_bitmap *bmp);
void_t redo_function(struct al_bitmap *bmp);
dword_t init_allegro5(struct allegro_sis *al);
void_t al_event_while();

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

/* Obtém a escrita do arquivo */
struct file_io_t write_file(struct file_io_t *file)
/* 
 * \brief
 *      Escreve o pintura em formato .jpg ou .png
 * \return
 *      Salvamento do arquivo
 */
{
    /* Sem implementação ainda */
    return *file;
}

/* Obtém a leitura, para poder abrir no futuro */
struct file_io_t read_file(struct file_io_t read)
/* 
 * \brief
 *      Obtém a leitura de um arquivo de imagem
 * \return
 *      Leitura jpg, png
 */
{
    /* Sem implementação ainda */
    return read;
}

/* IO, Obtém a entrada e saída de rotinas */
void_t get_file_procedure(FILE *fp, const char_t* unname)
/*  
 * Sem implementação ainda 
 * Atribuição para as rotinas de read e write
 */ 
/* 
 * \brief
 *      Recebe as função de read e write rotina
 * \return
 *      Obtém o valor exato de read e write rotina
 */
{ }

/* Obtém a coloração */
struct color_t get_color(struct color_t *ucolor)
/* 
 * \brief
 *      Estabelece uma char* de cor
 * \return
 *      cor padrão
 */
{   ucolor = 
    (struct color_t *)malloc(sizeof(struct color_t *));
    ucolor->r = 0x000;
    ucolor->g = 0x000;
    ucolor->b = 0x000;
    return *ucolor;
}

/* Allegro eventos */
void_t al_event_while() 
/* 
 * \brief
 *      Evento para iniciar o funcionamento correto do allegro 5
 * \return
 *      Evento e manipulação de keyboard
 */
{
    struct allegro_sis *sis;
    struct color_t *tcolor;
    
    /* That take other project */
    ALLEGRO_COLOR colors_buff[2][8] = {{al_map_rgb(255,0,0),   al_map_rgb(255,128,0), al_map_rgb(255,255,0),
        al_map_rgb(128,255,0), al_map_rgb(0,255,0),   al_map_rgb(0,255,128), al_map_rgb(64,64,64), al_map_rgb(0,0,0)},
        {al_map_rgb(0,255,255), al_map_rgb(0,128,255), al_map_rgb(0,0,255), 
            al_map_rgb(128,0,255), al_map_rgb(255,0,255), al_map_rgb(255,0,128), al_map_rgb(128,128,128), al_map_rgb(255,255,255)}
    };
    
    while(TRUE) {
        al_wait_for_event(sis->al_queue, &sis->al_event);
        
        switch(sis->al_event.type) {
            case KEYBOARD_EVENT_MOUSE_BUTTON_DOWN:
                al_get_mouse_state(&sis->al_mouse_state);
                if(al_mouse_button_down(&sis->al_mouse_state, 2)) {
                    undo_function();
                } else if (sis->al_mouse_state.y + 1 >= height) {
                    if(sis->al_mouse_state.x + 1 >= width /2 - 4 * SIZE - 4.4 * MARGIN  
                        && sis->al_mouse_state.x - 1 <= width /2 + 4 * SIZE + 4.5 * MARGIN 
                        &&  sis->al_mouse_state.y + 1 >= height) {

                    int location_x = (sis->al_mouse_state.x - (width/2 - 4* SIZE - 4.5* MARGIN + MARGIN - 0)) / (SIZE + MARGIN),
                        location_y = (sis->al_mouse_state.y - (height + MARGIN)) / (SIZE + MARGIN);
                    sis->al_color = colors_buff[location_y][location_x];
                    
                    cizx_toolbox_function();
                }

                if(sis->al_mouse_state.y > height + MARGIN_A && sis->al_mouse_state.y < height + MARGIN_A + SIZE_A) {
                    int i;
                    for(i=0 ; i<4 ; i++) {
                        if(sis->al_mouse_state.x > width /2 - 4 * SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A)*(i+1) 
                            && sis->al_mouse_state.x < width /2 - 4* SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) * (i+1) + SIZE_A) {
                            switch (i) {
                            case NO:
                                sis->int_mode = 3;  // draw line
                                break;
                            case YES:
                                sis->int_mode = 0;  // pencil
                                break;
                            case PODE:
                                if(sis->thickness >3.0)
                                    sis->thickness /= PHIA;
                                break;
                            case PODE_SE:
                                //if(thickness < 26)
                                sis->thickness *= PHIA;
                                break;
                            }
                        }
                    }
                    
                    for(i=0 ; i<5 ; i++) {
                        if(sis->al_mouse_state.x > width/2 + 4*SIZE + 4.5 * MARGIN + SIZE_A + (SIZE + MARGIN_A)*i 
                            && sis->al_mouse_state.x < width /2 + 4 * SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A)*i + SIZE_A) {
                            switch (i) {
                            case 0:
                                sis->int_mode = 4;
                                break;
                            case 1:
                                sis->int_mode = 1;
                                break;
                            case 2:
                                sis->int_mode = 5;
                                break;
                            case 3:
                                sis->int_mode = 2;
                                break;
                            case 4:         //  clean drawing area
                                tcolor->color = al_map_rgb(255,255,255);
                                al_draw_filled_rectangle(0, 0, width, height, tcolor->color);
                                al_flip_display();
                                al_wait_for_vsync();
                                add_revision_function();
                                break;

                            }
                        }
                    }
                    if(!sis->mouse_over) {
                        cizx_toolbox_function();
                    }
                }
            } else {
                    switch (sis->int_mode) {
                    case 0:
                        pencil_function();
                        add_revision_function();
                        break;
                    case 1:
                        triangle_function();
                        add_revision_function();
                        break;
                    case 2:
                        spray_function();
                        add_revision_function();
                        break;
                    case 3:
                        line_function();
                        add_revision_function();
                        break;
                    case 4:
                        rectangle_function();
                        add_revision_function();
                        break;
                    case 5:
                        circle_function();
                        add_revision_function();
                        break;
                    }
                    default: ;
                    break;
            }
            
            case KEYBOARD_EVENT_KEY_DOWN:
            if(sis->al_event.keyboard.keycode == KEY_KEY_S) {
                al_get_keyboard_state(&sis->al_keyboard_state);
                if(al_key_down(&sis->al_keyboard_state, KEY_KEY_LCTRL)) {
                    save_bitmap_function();
                }
            } else if(sis->al_event.keyboard.keycode == KEY_KEY_O) {
                al_get_keyboard_state(&sis->al_keyboard_state);
                if(al_key_down(&sis->al_keyboard_state, KEY_KEY_LCTRL)) {
                    open_bitmap_function();
                    add_revision_function();
                }
            } else if(sis->al_event.keyboard.keycode == KEY_KEY_Z) {
                al_get_keyboard_state(&sis->al_keyboard_state);
                if(al_key_down(&sis->al_keyboard_state, KEY_KEY_LCTRL)) {
                    undo_function();
                }
            } else if(sis->al_event.keyboard.keycode == KEY_KEY_Y) {
                al_get_keyboard_state(&sis->al_keyboard_state);
                if(al_key_down(&sis->al_keyboard_state, KEY_KEY_LCTRL)) {
                    redo_function();
                }
            } else if(sis->al_event.keyboard.keycode == KEY_KEY_Q) {
                al_get_keyboard_state(&sis->al_keyboard_state);
                if(al_key_down(&sis->al_keyboard_state, KEY_KEY_LCTRL)) {
                    al_destroy_display(sis->al_display);
                    al_destroy_event_queue(sis->al_queue);
                }
                break;
            }
            
            case KEYBOARD_EVENT_DISPLAY_CLOSE:
            al_destroy_display(sis->al_display);
            al_destroy_event_queue(sis->al_queue);
        }

        if(sis->mouse_over) {
            al_get_mouse_state(&sis->al_mouse_state);
            if(sis->al_mouse_state.y+10 > height + MARGIN_A 
                && sis->al_mouse_state.y - 10 < height + MARGIN_A + SIZE_A) {
                if(sis->al_mouse_state.x +10 > width /2 - 4 * SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A)*(4) 
                    && sis->al_mouse_state.x -10 < width /2 - 4 * SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A)*(1) + SIZE_A) {
                    cizx_toolbox_function();
                } else if(sis->al_mouse_state.x +10 > width /2 + 4 * SIZE + 4.5 * MARGIN + MARGIN_A 
                    && sis->al_mouse_state.x -10 < width /2 + 4 * SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A+ MARGIN_A)*4 + SIZE_A) {
                    cizx_toolbox_function();
                }
            }
        }
    }
} /* end al_event_while */

/* Obtém a init do allegro */
dword_t init_allegro5(struct allegro_sis *al)
/* 
 * \brief
 *      Obtém a inicialização original do allegro
 * \return
 *      É o main allegro
 */
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
    
    al->al_queue = al_create_event_queue();
    al_register_event_source(al->al_queue, al_get_mouse_event_source());
    al_register_event_source(al->al_queue, al_get_keyboard_event_source());
    al_register_event_source(al->al_queue, al_get_display_event_source(al->al_display));
    
    al_event_while();
}

/* Obtém as coords e posição dos icones */
void_t 
put_icon_position(struct bitmap_t *bitmap)
/* 
 * \brief
 *      Obtém as coordenadas dos icones
 * \return
 *      Posição e coords
 */
{ bitmap->size = SIZE; }

void_t draw_components()
{ /* Sem impl */ }

/* Obtém o resutado do keyboard */
dword_t 
get_more_less(dword_t size)
/* 
 * \brief
 *      Obtém a resultado do usuário,
 *          caso ele aperte + ou -
 *              para ampliar.
 * \return
 *      Keyboard Key
 */
{}

/* Armazenamento bitmap e sistema allegro */
void_t
add_revision_function(struct al_bitmap *bmp)
/* 
 * \brief
 *      Rotina que obtém armazenametos de variaveis de
 *          bitmap e do sistema allegro.
 * \return
 *      Armazenamento de valores.
 */
{ struct al_bitmap *cm;
  struct allegro_sis * sis;
  
  bmp = (struct al_bitmap *)malloc(sizeof(struct al_bitmap*));
  bmp->antes = cm;
  bmp->buffer = al_clone_bitmap(al_get_backbuffer(sis->al_display));
  cm = bmp;
}

/* Ferramentas do sistema */
void_t 
cizx_toolbox_function()
/* 
 * \brief
 *      Rotina, tem referencia as ferramentas do sistema
 * \return
 *      Ferramentas do sistema.
 */
{
    struct allegro_sis *sis;
    struct al_bitmap *bmp;
    
    al_draw_filled_rectangle(0, height, width, height + 2 * (SIZE) + 3 * MARGIN,
                             al_map_rgb(200, 200, 200));
    
    al_draw_filled_rectangle(width /2 - 4 * SIZE - 4.5 * MARGIN, height,
                             width /2 + 4 * SIZE + 4.5 * MARGIN, height + 2 * (SIZE) + 3 * MARGIN,
                             al_map_rgb(224, 224, 224));
    
    ALLEGRO_COLOR _color_ref[2][8] = 
    {
        {   al_map_rgb(255,0,0), al_map_rgb(255,128,0), al_map_rgb(255,255,0),
            al_map_rgb(128,255,0), al_map_rgb(0,255,0), al_map_rgb(0,255,128),
            al_map_rgb(64,64,64), al_map_rgb(0,0,0)
            
        },
        {al_map_rgb(0,255,255), al_map_rgb(0,128,255), al_map_rgb(0,0,255),
            al_map_rgb(128,0,255), al_map_rgb(255,0,255), al_map_rgb(255,0,128),
            al_map_rgb(128,128,128), al_map_rgb(255,255,255)
            
        }
    };
    
    int i,j;
    for(i=0; i<2 ; i++) {
        for(j=0 ; j<8 ; j++) {
            al_draw_filled_rectangle(width/2 - 4*SIZE - 4.5 * MARGIN + MARGIN + j*(SIZE +MARGIN),
                                     height + MARGIN + i*(SIZE +MARGIN),
                                     width/2 - 4*SIZE - 4.5 * MARGIN + MARGIN + j*(SIZE +MARGIN) + SIZE,
                                     height + MARGIN + i*(SIZE +MARGIN) + SIZE,
                                     _color_ref[i][j]);
        }
    }
    
    al_draw_filled_rectangle(MARGIN_A,
                             height + MARGIN_A,
                             MARGIN_A + SIZE_A,
                             height + MARGIN_A + SIZE_A,
                             al_map_rgb(224, 224, 224));

    al_draw_filled_rectangle(MARGIN_A + MARGIN,
                             height + MARGIN_A + MARGIN,
                             SIZE_A + SIZE_A - MARGIN,
                             height + MARGIN_A + SIZE_A -MARGIN,
                             sis->al_color);
    
        if(sis->mouse_over) {
        if(sis->al_mouse_state.y+1 > height + MARGIN_A 
            && sis->al_mouse_state.y-1 < height + MARGIN_A + SIZE_A) {
            for(i=0 ; i<4 ; i++) {
                if(sis->al_mouse_state.x + 1 > width/2 - 4 * SIZE- 4.5 * MARGIN - (MARGIN_A + SIZE_A) * (i+1) 
                    && sis->al_mouse_state.x + 1 <= width/2 - 4*SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) * (i+1) + SIZE_A) {
                    al_draw_filled_rectangle(width/2 - 4 *SIZE- 4.5 * MARGIN - (MARGIN_A + SIZE_A) * (i+1) - 3,
                                             height + MARGIN_A - 3,
                                             width/2 - 4 *SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) *(i+1) + SIZE_A +3,
                                             height + MARGIN_A + SIZE_A +3,
                                             al_map_rgb(128,128,128));
                }
            }

            for(i=0 ; i<5 ; i++) {
                if(sis->al_mouse_state.x + 1 > width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i 
                    && sis->al_mouse_state.x + 1 <= width/2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A+ MARGIN_A) *i + SIZE_A) {
                    al_draw_filled_rectangle(width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i - 3,
                                             height + MARGIN_A -3,
                                             width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i + SIZE_A +3,
                                             height + MARGIN_A + SIZE_A + 3,
                                             al_map_rgb(128,128,128));
                }
            }
        }
    }
    
    for(i=0 ; i<4 ; i++) {
        if(sis->int_mode == 0 && i == 1) {
            al_draw_filled_rectangle(width /2 - 4 *SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) *(i+1) -3,
                                     height + MARGIN_A - 3,
                                     width /2 - 4 *SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) *(i+1) + SIZE_A +3,
                                     height + MARGIN_A + SIZE_A +3,
                                     al_map_rgb(0, 0, 0));
        } else if(mode == 3 && i == 0) {
            al_draw_filled_rectangle(width /2 - 4 *SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A ) *(i+1) -3,
                                     height + MARGIN_A -3,
                                     width /2 - 4 *SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) *(i+1) + SIZE_A +3,
                                     height + MARGIN_A + SIZE_A +3,
                                     al_map_rgb(0, 0, 0));
        }
        al_draw_filled_rectangle(width /2 - 4 *SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) *(i+1),
                                 height + MARGIN_A,
                                 width /2 - 4 *SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) *(i+1) + SIZE_A,
                                 height + MARGIN_A + SIZE_A,
                                 al_map_rgb(224, 224, 224));
    }

    for(i=0 ; i<5 ; i++) {
        if(sis->int_mode == 1 
            && i == 1) {
            al_draw_filled_rectangle(width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A+ MARGIN_A) *i - 3,
                                     height + MARGIN_A - 3,
                                     width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i + SIZE_A +3,
                                     height + MARGIN_A + SIZE_A + 3,
                                     al_map_rgb(0, 0, 0));
        } else if(sis->int_mode == 4 && i==0) {
            al_draw_filled_rectangle(width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i -3,
                                     height + MARGIN_A - 3,
                                     width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i + SIZE_A +3,
                                     height + MARGIN_A + SIZE_A +3,
                                     al_map_rgb(0, 0, 0));
        } else if(sis->int_mode == 5 && i==2) {
            al_draw_filled_rectangle(width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i -3,
                                     height + MARGIN_A -3,
                                     width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i + SIZE_A +3,
                                     height + MARGIN_A + SIZE_A + 3,
                                     al_map_rgb(0, 0, 0));
        } else if(sis->int_mode == 2 && i==3) {
            al_draw_filled_rectangle(width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i -3,
                                     height + MARGIN_A - 3,
                                     width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i + SIZE_A +3,
                                     height + MARGIN_A + SIZE_A +3,
                                     al_map_rgb(0, 0, 0));
        }
        al_draw_filled_rectangle(width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i,
                                 height + MARGIN_A,
                                 width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *i + SIZE_A,
                                 height + MARGIN_A + SIZE_A,
                                 al_map_rgb(224, 224, 224));
    }
    
    bmp->bitmap = al_load_bitmap("png/plus.png");
    al_draw_scaled_bitmap(bmp->bitmap, 0, 0, al_get_bitmap_width(bmp->bitmap),
                          al_get_bitmap_height(bmp->bitmap),
                          width /2 - 4* SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) *(4) + MARGIN_A /2,
                          height + MARGIN_A + MARGIN_A /2, SIZE_A - MARGIN_A, SIZE_A - MARGIN_A, 0 );
    al_destroy_bitmap(bmp->bitmap);
    
    bmp->bitmap = al_load_bitmap("png/minus.png");
    al_draw_scaled_bitmap(bmp->bitmap, 0, 0,al_get_bitmap_width(bmp->bitmap),
                          al_get_bitmap_height(bmp->bitmap),
                          width /2 - 4 *SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) *(3) + MARGIN_A /2,
                          height + MARGIN_A + MARGIN_A /2, SIZE_A - MARGIN_A, SIZE_A - MARGIN_A, 0 );
    al_destroy_bitmap(bmp->bitmap);


    bmp->bitmap = al_load_bitmap("png/pen-tool.png");
    al_draw_scaled_bitmap(bmp->bitmap, 0, 0,al_get_bitmap_width(bmp->bitmap),
                          al_get_bitmap_height(bmp->bitmap),
                          width /2 - 4 *SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) *(2) + MARGIN_A /2,
                          height + MARGIN_A + MARGIN_A/2, SIZE_A - MARGIN_A, SIZE_A - MARGIN_A, 0 );
    al_destroy_bitmap(bmp->bitmap);

    bmp->bitmap = al_load_bitmap("png/graphic-tools.png");
    al_draw_scaled_bitmap(bmp->bitmap, 0, 0, al_get_bitmap_width(bmp->bitmap),
                          al_get_bitmap_height(bmp->bitmap),
                          width /2 - 4 *SIZE - 4.5 * MARGIN - (MARGIN_A + SIZE_A) *(1) + MARGIN_A /2,
                          height + MARGIN_A + MARGIN_A /2, SIZE_A- MARGIN_A, SIZE_A- MARGIN_A, 0 );
    al_destroy_bitmap(bmp->bitmap);

    bmp->bitmap = al_load_bitmap("png/rectangular.png");
    al_draw_scaled_bitmap(bmp->bitmap, 0, 0, al_get_bitmap_width(bmp->bitmap),
                          al_get_bitmap_height(bmp->bitmap),
                          width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A +MARGIN_A) *0 + MARGIN_A/2,
                          height + MARGIN_A + MARGIN_A /2, SIZE_A -MARGIN_A, SIZE_A -MARGIN_A, 0 );
    al_destroy_bitmap(bmp->bitmap);

    bmp->bitmap = al_load_bitmap("png/slope.png");
    al_draw_scaled_bitmap(bmp->bitmap, 0, 0, al_get_bitmap_width(bmp->bitmap),
                          al_get_bitmap_height(bmp->bitmap),
                          width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A)*1 + MARGIN_A /2,
                          height + MARGIN_A + MARGIN_A/2, SIZE_A- MARGIN_A, SIZE_A- MARGIN_A, 0 );
    al_destroy_bitmap(bmp->bitmap);

    bmp->bitmap = al_load_bitmap("png/circle.png");
    al_draw_scaled_bitmap(bmp->bitmap, 0, 0, al_get_bitmap_width(bmp->bitmap),
                          al_get_bitmap_height(bmp->bitmap),
                          width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A +MARGIN_A) *2 + MARGIN_A /2,
                          height + MARGIN_A + MARGIN_A /2, SIZE_A - MARGIN_A, SIZE_A - MARGIN_A, 0 );
    al_destroy_bitmap(bmp->bitmap);

    bmp->bitmap = al_load_bitmap("png/spray.png");
    al_draw_scaled_bitmap(bmp->bitmap, 0, 0, al_get_bitmap_width(bmp->bitmap),
                          al_get_bitmap_height(bmp->bitmap),
                          width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *3 + MARGIN_A /2,
                          height + MARGIN_A + MARGIN_A/2, SIZE_A- MARGIN_A, SIZE_A - MARGIN_A, 0 );
    al_destroy_bitmap(bmp->bitmap);

    bmp->bitmap = al_load_bitmap("png/trash.png");
    al_draw_scaled_bitmap(bmp->bitmap, 0, 0, al_get_bitmap_width(bmp->bitmap),
                          al_get_bitmap_height(bmp->bitmap),
                          width /2 + 4 *SIZE + 4.5 * MARGIN + MARGIN_A + (SIZE_A + MARGIN_A) *4 + MARGIN_A /2,
                          height + MARGIN_A + MARGIN_A /2, SIZE_A- MARGIN_A, SIZE_A- MARGIN_A, 0 );
    al_destroy_bitmap(bmp->bitmap);

    al_flip_display();
    al_wait_for_vsync();
}

void_t 
pencil_function()
{}

void_t 
triangle_function()
{}

void_t 
line_function()
{}

void_t 
rectangle_function()
{}

void_t 
spray_function()
{}

void_t 
circle_function()
{}

void_t 
save_bitmap_function()
{}

void_t 
open_bitmap_function()
{}

/* Undo */
void_t 
undo_function(struct al_bitmap *bmp)
/* 
 * \brief
 *      Obtém a volta p/ trás
 * \return
 *      Volta atrás.
 */
{ bmp = (struct al_bitmap *)malloc(sizeof(struct al_bitmap*));
  switch(bmp->int_result) {
      NO:
    case NO:
        al_draw_bitmap(bmp->antes->buffer, 0, 0, 0);
        bmp = bmp->antes;
        cizx_toolbox_function();
    break;
    ;
    case YES:
        goto NO;
    break;
  }
}

/* Redo */
void_t 
redo_function(struct al_bitmap *bmp)
/* 
 * \brief
 *      Obtém o avanço.
 * \return
 *      Avança p/ frente.
 */
{
    switch(bmp->int_result) {
        case NO:
            goto YES;
        break;
        
        YES:
        case YES:
            al_draw_bitmap(bmp->prox->buffer, 0, 0, 0);
            bmp = bmp->prox;
            cizx_toolbox_function();
        break;
        ;
    }
}

/* Keyboard keys */
dword_t tam_keyboard_arrow(struct pen_t *pen, dword_t size)
/* 
 * \brief
 *      Obtém o tamanho de + e - pressionado pelo usuário.
 * \return
 *      Keyboard keys.
 */
{
    return size;
}

/* ----------------------------------------------------------------------- */

int main(void) {
    return PROGRAM_SUCCESS;
}
