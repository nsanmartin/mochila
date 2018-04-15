read.resumen <- function(filename) {
    resu <- read.table (filename, row.names=NULL)
    names(resu) <- c("n", "W", "fb", "bt", "mm", "din")

    resu
}


resumen.medias <- function(resu) {
    ns <- unique(resu$n)
    Ws <- unique(resu$W)
    medias <- c()
    for (i in ns) {
        for (j in Ws) {
            tmptab <- as.data.frame(resu[resu$n==i ,])
            tmptab <- as.data.frame(tmptab[tmptab$W==j,])
            medias <- rbind(medias, colMeans(tmptab))
        }
    }
    data.frame(medias)
}

resumen.sd <- function(resu) {
    ns <- unique(resu$n)
    Ws <- unique(resu$W)
    desvios <- c()
    for (i in ns) {
        for (j in Ws) {
            nw <- resumen(resu, i, j)
            d.s <- data.frame(i, j)
            for (k in 3:(length(names(resu)))) {
                nw.sd <- sd(nw[[k]])

                d.s <- cbind(d.s, data.frame(nw.sd))
            }
            
            desvios <- rbind(desvios, d.s)
        }
    }
    names(desvios) <- c("n", "W", "fb", "bt", "mm", "din")
    desvios
}

resumen <- function(resu, n, W) {
    resu <- as.data.frame(resu[resu$n==n ,])
    resu <- as.data.frame(resu[resu$W==W,])
    resu
}


resumen.medias.Ws <- function(resu) {
    Ws <- unique(resu$W)
    medias <- c()
    for (j in Ws) {
        tmptab <- as.data.frame(resu[resu$W==j,])
        medias <- rbind(medias, colMeans(tmptab))
    }
    data.frame(medias)[2:dim(resu)[2]]
}

resumen.medias.ns <- function(resu) {
    ns <- unique(resu$n)
    medias <- c()
    for (i in ns) {
        tmptab <- as.data.frame(resu[resu$n==i ,])
        medias <- rbind(medias, colMeans(tmptab))
        
    }
    data.frame(medias)[c(1,3:dim(resu)[2])]
}

    
