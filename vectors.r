vetor1 <- c(6, 3, 2)

# formas de criar um vetor
vetor2 <- c(5, 10, 15)
vetor2 <- seq(5, 15, 5)
print(vetor2) # saída: 5 10 15
vetor2 <- seq(5, 15, length.out = 3)
print(vetor2) # saída: 5 10 15

vetor3 <- 1:4
print(vetor3) # saída: 1 2 3 4

# formas de acessar o vetor
print(vetor3) # vetor inteiro, saída: 1 2 3 4
print(vetor3[1]) # um elemento, saída: 1
print(vetor3[-2]) # ignorar um elemento, saída: 1 3 4
print(vetor3[2:3]) # sequencia de posições, saída: 2 3
print(vetor3[vetor3 < 3]) # operador lógico, saída: 1 2

# operações com vetor
print(vetor1 * 2) # saída: 10 20 30
print(vetor1**4) # saída: 625 10000 50625
print(vetor1 + vetor3[vetor3 > 1]) # saída: 8 6 6
print(vetor1 * vetor2) # saída: 30 30 30
print(vetor2 / vetor3[1:3]) # saída: 5 5 5