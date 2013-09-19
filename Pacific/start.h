// Inicializar as variaveis

bool inicializar()
{
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return false;
    }
 
    al_init_font_addon();
 
    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return false;
    }
 
    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_primitives.\n");
        return false;
    }

    if (!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return false;
    }
 
    if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        return false;
    }
 
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }
 
    al_set_window_title(janela, "Pacific Transit 1.3.5");
 
    fonte = al_load_font("SourceCodePro-Regular.ttf", 72, 0);
    if (!fonte)
    {
        fprintf(stderr, "Falha ao carregar \"fonte comic.ttf\".\n");
        al_destroy_display(janela);
        return false;
    }
 
    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return false;
    }
 
    fundo = al_load_bitmap("bg.png");
    if (!fundo)
    {
        fprintf(stderr, "Falha ao carregar imagem de fundo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }

    menu = al_load_bitmap("menu.jpg");
    if (!menu)
    {
        fprintf(stderr, "Falha ao carregar imagem de menu.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }
 
    carro = al_load_bitmap("carro.png");
    if (!carro)
    {
        fprintf(stderr, "Falha ao carregar imagem do carro .\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }

    carro2 = al_load_bitmap("carro2.png");
    if (!carro2)
    {
        fprintf(stderr, "Falha ao carregar imagem do carro2 .\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }

    if(!al_install_audio())
    {
     fprintf(stderr, "Falha ao inicializar o audio.\n");
        return false;
     }
    
    if(!al_init_acodec_addon())
    {
        fprintf(stderr, "Falha ao iniciar o audio codec.!\n");
      return false;
    }
    
    if (!al_reserve_samples(1))
    {
        fprintf(stderr, "Falha ao alocar canais de audio.\n");
        return false;
    }

    som = al_load_sample("som.wav"); 

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    return true;
}