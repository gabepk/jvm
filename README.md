# Java Virtual Machine

## Introdução
Implementação em C++ de uma Java Virtual Machine simplificada com base no Java 2 para a disciplina de Software Básico na Universidade de Brasília do semestre 2/2015.

A maior parte das instruções presentes no bytecode do Java 2 estão implementadas, exceto: ```monitorenter, monitorexit, athrow```.

A implementação também simula funcionalidades básicas de I/O (e.g. `System.out.println()`) e de strings.

## Instruções e Recomendações
* Siga o [fluxograma proposto](https://googledrive.com/host/0B_YEQWAPOAO3b3lwZmZTTGNONjg) e sugira melhorias.
* Para criar sua funcionalidade, sempre crie um branch a partir do dev.
* Sempre faça pull antes de começar a trabalhar e de fazer um push.
* Sempre crie commits explicativos, para que possamos voltar pra algum commit caso dê algo errado.
* Antes de fazer o merge de sua funcionalidade no dev, sempre faça o rebase com o dev, resolva os conflitos (quando houver), e verifique se está tudo funcionando.
* Se a funcionalidade estiver pronta (e também compilando e funcionando) após o rebase com o dev, faça o merge com o dev.
* Documente o código usando o [Doxygen](https://www.stack.nl/~dimitri/doxygen/manual/docblocks.html) no padrão Javadoc.
* Sempre que criar um novo arquivo .c/.cpp, adicione-o em CMakeLists.txt.

## Pastas do Projeto
* Os arquivos .c/.cpp estão contidos na pasta /src
* Os arquivos .h/.hpp estão contidos na pasta /include
* Exemplos de programas .java (e seus respectivos .class) estão em /exemplos
* A documentação está contida na pasta /docs

## Geração de Arquivos .class
Para gerar um arquivo .class de um programa .java, rode o seguinte comando:   
```javac -source 1.2 -target 1.2 programa.java```

## Compilação do Projeto
Para compilar o projeto, primeiro crie uma pasta na raiz do projeto:  
```mkdir build && cd build```  
Com isso feito, rode o CMake e faça o make:  
```cmake .. && make```  
O arquivo executável será então criado, pronto para ser executado.

## Execução
* ```./jvm arquivo.class``` (irá executar o programa contido em arquivo.class)
* ```./jvm arquivo.class saida.txt``` (irá executar o programa contido em arquivo.class e irá mostrar a estrutura formatada do arquivo .class em saida.txt)

Existe o arquivo Test.class na pasta ```examples```, um simples programa que calcula o 42º elemento da sequência de Fibonacci, você pode usar ele como teste para a primeira execução. Lembre-se de colocar o arquivo .class no mesmo diretório que o executável.

Além disso, verifique se a pasta `java` se encontra no mesmo diretório que o executável, para que a classe Object.class possa ser encontrada pela JVM. O CMake irá automatizar isso, mas saiba disso caso compile o projeto de outra maneira.

## Gerando a Documentação
Para gerar a documentação, rode o seguinte comando na raiz do projeto: ```doxygen```   
Com isso feito, a documentação em HTML estará em doxygen/html/ e em LaTeX estará em doxygen/latex/.

## Referências
* [Especificação da JVM - 2ª edição](http://web.cecs.pdx.edu/~apt/vmspec/VMSpecTOC.doc.html)
* [Noções Básicas de Git](https://git-scm.com/book/pt-br/v1/Primeiros-passos-Noções-Básicas-de-Git)
* [SourceTree - cliente git com interface gráfica](https://www.sourcetreeapp.com)
* [CMake 3.3.2 - download](https://cmake.org/download/)
* [Explicação em português do .class](http://www.mentebinaria.com.br/zine/edicoes/1/ClassInjection.txt)

## Desenvolvedores
* Ana Paulino
* Arthur Emídio
* Gabriella Esteves
* Matheus Andrade
* Matheus Bastos
