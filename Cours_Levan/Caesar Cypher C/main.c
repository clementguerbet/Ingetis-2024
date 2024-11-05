#include <stdio.h>
#include <string.h>

void ListePairs(int N) {
    int i;
    for (i = 0; i <= N; i += 2) {
        printf("%d ", i); 
    }
    printf("\n");
}

void ListeImpairs(int N) {
    int i;
    for (i = 0; i <= N; i += 1) {
        if (i % 2 == 1) {
            printf("%d ", i); 
        }
    }
    printf("\n");
}

int Factorielle(int N) {
    int fact = 1;
    for (int i = 1; i <= N; i++) {
        fact = fact * i;
    }  
    return fact;
}

int Fibonnacci(int N) {
    if(N <= 1)
        return N;
    else 
        return Fibonnacci(N - 2) + Fibonnacci(N - 1);
}

int palindrome(const char* chaine) {
    int taille = strlen(chaine);
    char inverser[100];
    for (int i = 0; i < taille; i++) {
        inverser[i] = chaine[taille - 1 - i];
    }
    inverser[taille] = '\0';
    return strcmp(chaine, inverser) == 0;
}

void cesar(char message[], int decal) {
    int i = 0;
    while (message[i] != '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' + decal) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' + decal) % 26;
        }
        i++;
    }
}

int main() {
    int N; 
    printf("Entre un chiffre : ");
    scanf("%d", &N);
    printf("Nombres pairs de 0 à %d : ", N);
    ListePairs(N);
    printf("Nombres impairs de 0 à %d : ", N);
    ListeImpairs(N);
    printf("La factorielle de %d est égale à : %d\n", N, Factorielle(N));
    printf("Le terme de rang %d de la suite de Fibonacci est : %d\n", N, Fibonnacci(N));
    
    char chaine[100];
    printf("Entrez une chaîne à vérifier si elle est un palindrome : ");
    scanf("%s", chaine);
    if (palindrome(chaine)) {
        printf("\"%s\" est un palindrome.\n", chaine);
    } else {
        printf("\"%s\" n'est pas un palindrome.\n", chaine);
    }

    char message[100];
    int decal = 3;
    printf("Entrez un message à encrypter avec le code César :\n");
    scanf("%s", message);
    cesar(message, decal);
    printf("Le message chiffré est : %s\n", message);
    if (palindrome(message)) {
        printf("Le message chiffré \"%s\" est un palindrome.\n", message);
    } else {
        printf("Le message chiffré \"%s\" n'est pas un palindrome.\n", message);
    }

    return 0;
}