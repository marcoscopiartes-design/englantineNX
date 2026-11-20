#include <switch.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define ROOT "sdmc:/Eglantine NX"
#define CONFIG ROOT "/Config"
#define GAMES ROOT "/Games"
#define SYSTEM ROOT "/System"
#define SHADERS ROOT "/Shaders"
#define LOGS ROOT "/Logs"
#define SETTINGS CONFIG "/settings.ini"

static void make_dir(const char *path) {
    mkdir(path, 0777);
}

static void prepare_files(void) {
    make_dir(ROOT);
    make_dir(CONFIG);
    make_dir(GAMES);
    make_dir(SYSTEM);
    make_dir(SHADERS);
    make_dir(LOGS);

    FILE *f = fopen(SETTINGS, "w");
    if (f) {
        fputs("# Eglantine NX - configuracao inicial\n", f);
        fputs("fps_limit_target=40\n", f);
        fputs("fps_limit_60_enabled=false\n", f);
        fputs("first_run_complete=true\n", f);
        fclose(f);
    }
}

int main(int argc, char* argv[]) {
    consoleInit(NULL);
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    PadState pad;
    padInitializeDefault(&pad);

    bool installed = false;
    bool show_notice = false;
    int selection = 0;

    while (appletMainLoop()) {
        padUpdate(&pad);
        u64 down = padGetButtonsDown(&pad);

        consoleClear();
        printf("\x1b[1;36m");
        printf("          EGLANTINE NX\n");
        printf("\x1b[0m");
        printf("----------------------------------------\n\n");

        if (!installed) {
            printf(" Bem-vindo ao Eglantine NX!\n\n");
            printf(" Este assistente prepara as pastas do\n");
            printf(" aplicativo no cartao SD.\n\n");
            printf(" Os arquivos de firmware e keys NAO\n");
            printf(" estao incluidos neste aplicativo.\n\n");
            printf("%s CONTINUAR\n", selection == 0 ? " >" : "  ");
            printf("%s CANCELAR\n", selection == 1 ? " >" : "  ");
            printf("\n A/B: selecionar    Cima/Baixo: mover\n");

            if (down & (HidNpadButton_Up | HidNpadButton_Down))
                selection = 1 - selection;

            if (down & HidNpadButton_A) {
                if (selection == 0) {
                    prepare_files();
                    installed = true;
                    show_notice = true;
                } else {
                    break;
                }
            }
            if (down & HidNpadButton_B) break;
        } else if (show_notice) {
            printf(" CONFIGURACAO NECESSARIA\n\n");
            printf(" As pastas foram preparadas.\n\n");
            printf(" Para configurar o sistema, o usuario\n");
            printf(" precisa fornecer arquivos de firmware\n");
            printf(" e keys obtidos legalmente do proprio\n");
            printf(" console. Este prototipo apenas prepara\n");
            printf(" as pastas; ainda nao valida esses arquivos.\n\n");
            printf(" Pressione A para continuar.\n");
            if (down & (HidNpadButton_A | HidNpadButton_B))
                show_notice = false;
        } else {
            printf(" INSTALACAO DE TESTE CONCLUIDA\n\n");
            printf(" Pastas criadas em:\n%s\n\n", ROOT);
            printf(" Preferencia salva: limite desejado 40 FPS\n");
            printf(" (a limitacao de FPS ainda nao esta implementada)\n\n");
            printf(" Este e um prototipo de interface e instalador.\n");
            printf(" Ele NAO emula jogos de Switch 2.\n\n");
            printf(" Pressione B para sair.\n");
            if (down & HidNpadButton_B) break;
        }

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
