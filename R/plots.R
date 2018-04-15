library(reshape2)
library(ggplot2)

plot.lineas.W <-  function (df, col) {
    ggplot(data=df, aes_string(x="W", y="media_ms")) +
        geom_line(aes_string(y=col), col="red") +
        ggtitle(col)
}

plot.lineas.n <-  function (df, col) {
    ggplot(data=df, aes_string(x="n", y="media_ms")) +
        geom_line(aes_string(y=col), col="red") +
        ggtitle(col)
}

plot.lineas.W4 <-  function (df) {
    fb <- plot.lineas.W(df,"fb")
    bt <- plot.lineas.W(df,"bt")
    mm <- plot.lineas.W(df,"mm")
    din <- plot.lineas.W(df,"din")
    multiplot(fb, bt,mm,din, cols=2) 
}

plot.lineas.n4 <-  function (df) {
    fb <- plot.lineas.n(df,"fb")
    bt <- plot.lineas.n(df,"bt")
    mm <- plot.lineas.n(df,"mm")
    din <- plot.lineas.n(df,"din")
    multiplot(fb, bt,mm,din, cols=2) 
}




multiplot <- function(..., plotlist=NULL, file, cols=1, layout=NULL) {
    require(grid)
    plots <- c(list(...), plotlist)
    numPlots = length(plots)
    if (is.null(layout)) {
        layout <- matrix(seq(1, cols * ceiling(numPlots/cols)),
                         ncol = cols, nrow = ceiling(numPlots/cols))
    }
    if (numPlots==1) {
        print(plots[[1]])

    } else {
        grid.newpage()
        pushViewport(
            viewport(layout = grid.layout(nrow(layout), ncol(layout))))
        for (i in 1:numPlots) {
            matchidx <- as.data.frame(which(layout == i, arr.ind = TRUE))
            print(plots[[i]], vp
                  = viewport(layout.pos.row = matchidx$row,
                             layout.pos.col = matchidx$col))
        }
    }
}

plot.save <- function(p, filename) {
    cat("Abriendo para escribir: ", filename, "\n")
    png(filename)
    print(p)
    dev.off()
}
