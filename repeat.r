# programa que encontra o menor inteiro positivo que
# quando divido por 3, 5 e 7 de resto 2, 3 e 4 respectivamente


# começar em 11 pois e o menor número que dividido por 7 da resto 4
# mas podemos mudar ele para qualquer inteiro positivo
n <- 11

repeat {
    if (n %% 3 == 2) {
        if (n %% 5 == 3) {
            if (n %% 7 == 4) {
                cat(n, "\n")
                break
            }
        }
    }
    n <- n + 1
}