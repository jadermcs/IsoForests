# Dirty Deputies

Último projeto da matéria de Teoria e Aplicação de Grafos (TAG) do semestre de 2017/1.

## Execução

Para executar este programa basta executar os seguintes comandos no terminal:

```
  $ bash run_all.sh
```

Este comando acima compila o programa utilizando o [Makefile](https://github.com/Dayof/dirty-deputies/Makefile) e já o executa em seguida. Caso queira só executar o programa sem necessariamente compilar novamente, executar o seguinte comando:

```
  $ ./main
```

## Pré-requisitos do sistema

Este programa foi testado no sistema operacional ``macOS Sierra``, versão ``10.12``. A linguagem de programação utilizada para implementar todo o projeto foi ``C++11``.

### Funcionalidades

O programa realiza as seguintes funcionalidades a partir do menu principal:

- Opção 1 : Mostra as anomalias encontradas pelo nosso algoritmo.

- Opção 2 : Realiza uma busca pelos parlamentares, utilizando seu identificador ou busca todos os parlamentares de um certo estado ou partido, e realizando a soma dos gastos.

- Opção 3 : Mostra todos os parlamentares, com seus respectivos indicadores e informações de partido e estado.

- Opção 4 : Mostra todas as empresas envolvidas com os gastos.

- Opção 5 : Mostra o grafo completo.                               

- Opção 6 : Exibe tela de ajuda sobre o sistema.

- Opção 7 : Sai do sistema.

### Fluxo do programa

O arquivo ``process_db.py`` filtra as 8 primeiras colunas do arquivo ``dirty_deputies_v2.csv`` e cria um arquivo texto ``dirty_deputies.txt`` que será usado como arquivo de entrada para o sistema. Ao executar o sistema com o arquivo ``run_all.sh`` ele irá compilar e executar o sistema. O início do sistema pode demorar aproximadamente 1 minuto para processar todo o banco de dados de reembolsos dos deputados para o grafo geral.

Existem 2 tipos de vértices no grafo, um vértice do tipo ``dVertex``, que representa a entidade do deputados com nome, estado e partido de cada deputado e vértices do tipo ``cVertex``, representando a entidade de uma empresa, contendo nome da empresa e o número de identificação. Este vértices são ligados através de arestas que representam as transações realizadas entre eles. Nas arestas contêm o tipo de gasto da transação, a data e o valor.

Ao iniciar o programa uma interface irá aparecer para o usuário interagir com o sistema. As opções 2, 3, 4 e 5 são interações com o grafo gerado. A opção 1 é a funcionalidade que checa anomalias nas comunidades encontradas no grafo. Cada comunidade foi subdividida através dos gastos de um determinado deputado.

As anomalias são calculadas usando o desvio padrão dentro de cada comunidade.

## Autoria

- Dayanne Fernandes da Cunha
  - Matrícula: 13/0107191
  - E-mail: dayannefernandesc@gmail.com
  - GitHub: [Dayof](https://github.com/Dayof)

- Renato Avellar Nobre
  - Matrícula: 15/0146698
  - E-mail: rekanobre@gmail.com
  - GitHub: [Skalwalker](https://github.com/Skalwalker)
