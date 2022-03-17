# feito com R 3.6.3
if (!grepl("3.6.3", version$version.string)) {
    cat("Sua versão é mais antiga que 3.6.3\n")
    q()
} else {
    cat("\nSua versão é atualizada!\n")
}

# como R não possui operador +=
`%+=%` <- function(a, b) eval.parent(substitute(a <- a + b))
soma <- 0
if (is.function(`%+=%`) && exists("soma")) {
    soma %+=% 1
    cat("\nsoma =", soma, "\n\n")
} else { # nunca vai entrar
    cat("não possui operador `%+=%` ou variável 'soma'\n")
}

cat("Entre com %-=%, %*=% ou %/=% para o operador\n")
nome_operador <- readline("operador: ")
cat("para <operador>: <entre com>\n
    para %-=%: subtraendo\n
    para %*=%: produto\n
    para %/=%: quociente\n")
nome_variavel <- readline("nome da variavel: ")
if (nome_operador == "%-=%") {
    assign(nome_operador, function(a, b) eval.parent(substitute(a <- a - b)))
} else if (nome_operador == "%*=%") {
    assign(nome_operador, function(a, b) eval.parent(substitute(a <- a * b)))
} else {
    assign(nome_operador, function(a, b) eval.parent(substitute(a <- a / b)))
}

assign(nome_variavel, 20)

if (exists("subtraendo")) {
    subtraendo %-=% subtraendo
    cat("\nsubtraendo =", subtraendo, "\n\n")
} else {
    cat("não possui variável 'subtraendo'\n")
}
if (exists("produto")) {
    produto %*=% 5
    cat("\nproduto =", produto, "\n\n")
} else {
    cat("não possui variável 'produto'\n")
}
if (exists("quociente")) {
    quociente %/=% 10
    cat("\nquociente =", quociente, "\n\n")
} else {
    cat("não possui variável 'quociente'\n")
}