42sh
PROJECT STRUCTURE

libraries are in ./libs/. currently there is:
libgnl (for get_next_line)
libft (standard)
libprt (for printf. !segfault if you pass string to %d)
Colors are defined in libprt.h
Errors messages are defined by Macros in project header (ie. shell.h) and start with 'E_'
GIT WORKFLOW

Comme c'est un projet de groupe, je vous propose d'adopter la méthodologie de ce tuto sur youtube pour coordonner le development parallèle.

L'idee est simple:

Nous avons une branche publique et des branches privées.
Chacun travail sur sa branche privée et uniquement sur celui-ci. Une fois fini, nous faisons un 'pull request' et 'l'admin' procède a la validation du code avant de 'merge' avec la branche publique.
Sur un petit projet comme 42sh, la branche publique est 'master' et il sera toujours libre de bugs.

Voici les étapes:

Créer une copie du projet sur votre github.
se rendre sur <https://github.com/tongamite/42sh> et 'fork'
Cloner la copie sur votre machine.
git clone https:github.com/<your_pseudo>/42sh.git
Creer votre branche prive avec le nom de la fonctionnalité que vous implementez.
git checkout -b <your_branch_name>
C'est le raccourci pour:
git branch <name> && git checkout <name>
coder coder coder.
une fois le travail fini:
git add . && git commit -m "<quick summary>"
se rendre sur la page du projet et faire un 'pull request'
recommencer a partir de l'etape 3.
Emmanuel.

Presentation:

J'ai decidé de pusher une base sur laquelle on peut tous travailler et inserer nos travaux petit a petit. J'ai pris mon sh1 pour base. Il est opérationnel.

Rapide explication du code :

get_cmd() s'occupe de lire l'entree standard et retourne un char * venant d'un split sur les espaces. Tout simple. Cette partie va completement etre modifiée avec le lexer parser. On devra aussi inserer la partie ft_sh3 dedans. (je propose de prendre comme base le code Guillaume).

En gros le get_cmd devra a terme

- lire l'entree std ;
- s'occuper des termcaps (mappage des touches etc..) ;
- (LEXER) nettoyer la ligne de commande recue et en faire un tableau de char
    - ca prend en compte la gestion des guillemet,
    - des variables environnementale
    - des backslash
    - etc...
- (PARSER) recuperer le tableau du lexer et le transformer en arbre binaire.
Pour la partie EXECUTION, j'ai une bonne base qui s'occupe de gerer les multi-redirection, les multi-pipes etc... Je ne la push pas encore car c'est une ancienne version qui travaille avec des char ***** (HORREUR !). Du coup je la modifirais pour quelle travaille avec l'arbre du PARSER, je ne pense pas que ce sera compliqué

implimented_function() s'occupe de verifier si la commande a executer est un built-in ou pas. Retourne 1 si oui 0 sinon, -1 en cas d'erreur.

TO_DO pour avoir 10:

Reconstruire un shell propre avec: - lexer - parser - execution (avec multi-pipes/redir etc..)
//la partie exec ne devrais pas prendre bcp de temps.
//La plupart du code est deja la.
- mon cd ne gere pas le cd - - echo - heredoc

TO_DO (LEXER) :

a partir d'un char *
gestion des " et ' et \
gestion variables environnementale
retourne tableau
TO_DO (PARSER) :

a partir d'un char **
organisation en arbre en fonction de
;
&&
||
<
>
>>
|
TO_DO (EXECUTION) :

adapter le code pour recevoir un arbre au lieu de char *
TO_DO (FT_SH3) : (a completer par GUILLAUME)

deplacement mots par mots;
auto_completion
