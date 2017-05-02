reset
set key on
set terminal png size 1280,960 enhanced font 'Helvetica,12'
set output './results/grafico-rec.png'
set title 'Multiplicação de matrizes (recursão)'
set grid
set xrange[0:512]
set xtics 50
set ytics 2673.36
set xlabel 'Tamanho da matriz'
set ylabel 'Tempo gasto (ms)'
set xtic rotate by -90 scale 0
set yrange[0:53500]
plot './results/stats-rec.dat' using 1:4 title 'Tempo médio' lw 2 with lines
