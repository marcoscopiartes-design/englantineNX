# Eglantine NX — projeto de teste

Este pacote contém o **código-fonte** de um protótipo homebrew para Nintendo Switch.

## O que o protótipo faz
- Mostra uma tela inicial com CONTINUAR e CANCELAR.
- Ao continuar, cria `sdmc:/Eglantine NX/` e as subpastas `Games`, `System`, `Config`, `Shaders` e `Logs`.
- Grava `Config/settings.ini` com uma preferência de 40 FPS.
- Mostra um aviso informando que firmware e keys precisam ser fornecidos pelo próprio usuário.

## O que ainda não faz
- Este ZIP **não é um arquivo NRO pronto**.
- Não contém firmware nem keys.
- Não valida firmware/keys.
- Não implementa emulação, renderização de jogos ou limitador real de FPS.
- Não consegue executar jogos de Switch 2 no hardware do Switch 1.

## Como compilar
É necessário um PC com Windows, Linux ou macOS e o ambiente oficial devkitPro configurado com devkitA64 e libnx.

Depois de instalar e configurar o ambiente:
1. Extraia o ZIP.
2. Abra um terminal na pasta do projeto.
3. Execute `make`.
4. O NRO será gerado na pasta `build/`, se a compilação terminar sem erros.

O ícone `icon.jpg` é provisório. A exibição e os metadados podem variar conforme o carregador homebrew utilizado.
