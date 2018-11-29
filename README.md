# Sistema de Gerenciamento de Banco de Dados Simplificado - Projeto ITP - 2018.2

## Como usar:

Será necessário para a compilação do programa:
* ''make''
* ''gcc''

Para compilar basta clonar o repositório, entrar no diretório raiz do projeto e digitar no terminal:
''make''

Para rodar o programa use:
''./bin/dbms_itp''

Para deletar os arquivos gerados na compilação use:
''make clean''

Para deletar os arquivos gerados na compilação e na execução do programa use:
'''make cleanall'''

## Informações sobre o projeto

Nesse projeto, foi implementado um Sistema de Gereciamento de Banco de Dados de forma simplificada em C, com a finalidade de explorar os conhecimentos na linguagem.

### Funcionalidades:

* **Adicionar tabela**
* **Adicionar linha em uma tabela**
* **Listar o nome das tabelas criadas**
* **Mostrar tabela completa**
* **Pesquisas por:**
	* Valores maiores que o valor informado
	* Valores maiores ou iguais ao valor informado
	* Valores iguais ao valor informado
	* Valores menores que o valor informado
	* Valores menores ou iguais ao valor informado
	* Valores próximos (somente para strings)
* **Deletar tabela**
* **Deletar linha**

### Requisitos atendidos:

Foram atendidos os seguintes requisitos na realização do código-fonte:

* Alocação dinâmica
* Leitura e escrita a partir de arquivos
* Modularização interna e externa
* Uso de boas práticas de programação
* Todos os erros emitidos via 'stderr'
* Documentação adequada

