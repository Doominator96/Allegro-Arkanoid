#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>

#include "GestoreGioco.h"

using namespace std;
int main(int argc, char **argv){
  Vaus v;
const float FPS=60;
  bool done=false, draw = true;
  if (!al_init())
  {
    cerr << "no allegro" << endl;
    return -1;
  }
  if (!al_init_image_addon())
  {
    cerr << "failed initialisation image" << endl;
    return -1;
  }
  if (!al_init_primitives_addon())
  {
    cerr << "failed initialisation primitives" << endl;
    return -1;
  }
  if (!al_init_native_dialog_addon())
  {
    cerr << "failed initialisation dialog" << endl;
    return -1;
  }
  if (!al_init_font_addon())
  {
    cerr <<"Font initialization failed"<< endl;
    return -1;
  }
  if (!al_init_ttf_addon())
  {
    cerr <<"Font initialization failed"<< endl;
    return -1;
  }
  if (!al_install_mouse())
  {
    cerr << "no mouse" << endl;
    return -1;
  }

  if(!al_install_keyboard()) {
    cerr<<"no keyboard"<<endl;
    return -1;
  }


  ALLEGRO_DISPLAY* display = al_create_display(800, 600);
  ALLEGRO_SAMPLE* sample=NULL;
  if (!display)
  {
    cerr << "no display" << endl;
    return -1;
  }
  al_set_window_title(display,"Arkanoid");

  if(!al_install_audio()){
    cerr<< "no audio"<<endl;
    }

    if(!al_init_acodec_addon()){
      cerr<< "failed to initialize audio codecs!"<<endl;
      return -1;
   }

   if (!al_reserve_samples(1)){
      cerr<< "failed to reserve samples!"<<endl;
      return -1;
   }

   sample = al_load_sample( "Sound.ogg" );

   if (!sample){
    cerr<<"Audio clip sample not loaded!"<<endl ;
      return -1;
    }

  ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
  if (!event_queue)
  {
    cerr << "no event_queue" << endl;
    return -1;
  }

  ALLEGRO_KEYBOARD_STATE keyState;

  ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_timer_event_source(timer));


  al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
  ALLEGRO_BITMAP* Sfondo = al_load_bitmap("background.jpg");
  ALLEGRO_BITMAP* Play = al_load_bitmap("Play.png");
  ALLEGRO_BITMAP*   paddle=al_load_bitmap("paddle.png");
  ALLEGRO_FONT* text =al_load_font("Arka_solid.ttf",100,0);
  if (!Sfondo)
  {
    cerr << "No Bitmap" << endl;
    return -1;
  }

  int play_x = 288,play_y=300,credits_x=600,credits_y=700,x=0,y=0,dimW=224,dimH=100;
  al_clear_to_color(al_map_rgb(0,0,0));
  al_draw_bitmap(Sfondo,0,0,0);
  al_draw_bitmap(Play,288,300,0);
  al_draw_text(text,al_map_rgb(255,255,255),150,50,0,"ARKANOID");

  al_flip_display();


  while(x<play_x || x>credits_x+dimW || x>play_x+dimW && x<credits_x || y>play_y+dimH || y<play_y){
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
      if(ev.keyboard.keycode == ALLEGRO_KEY_M){
        al_stop_sample_instance(al_create_sample_instance(sample));
      }


    if(ev.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP){
      x = ev.mouse.x;
      y = ev.mouse.y;
    }
    if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE){
      al_destroy_bitmap(Sfondo);
      al_destroy_event_queue(event_queue);
      al_destroy_display(display);
      al_destroy_sample(sample);
      al_destroy_bitmap(Play);

      return 0;
    }


  }
  al_destroy_bitmap(Sfondo);
  al_destroy_bitmap(Play);



  GestoreGioco ark;
  al_start_timer(timer);
while(!done){
  ALLEGRO_EVENT events;
  al_wait_for_event(event_queue, &events);

  if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
  {
    al_destroy_bitmap(Sfondo);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_sample(sample);
    al_destroy_bitmap(Play);

    return 0;
  }
  if(events.type == ALLEGRO_EVENT_TIMER)
  {
    al_get_keyboard_state(&keyState);
    if(al_key_down(&keyState, ALLEGRO_KEY_RIGHT)&&v.getX()+104<798)
      v.setX(v.getX()+5);
    if(al_key_down(&keyState, ALLEGRO_KEY_LEFT) && v.getX()>0)
      v.setX(v.getX()-5);
      // cout<<v.getX();
      ark.collisionControl(v,1);
      ark.b.movements();
  }
  ark.draw(1);
  al_draw_bitmap(paddle,v.getX(),v.getY(),0);
  al_draw_bitmap(ark.ball,ark.b.getX(),ark.b.getY(),0);
  al_flip_display();

 if(ark.b.getY()>=600){
   cout<<"morto"<<endl;
   // if(v.getLives()==0){
   // }
   v.setLives(v.getLives()-1);
   ark.b.ballReset();
   ark.b.setDy(-ark.b.getDy());
   v.vausReset();

 }

}

    al_rest(3);


  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  al_destroy_sample(sample);
  al_destroy_timer(timer);


  return 0;
}
