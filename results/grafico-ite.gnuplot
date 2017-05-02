reset
set key on
set terminal png size 1280,960 enhanced font 'Helvetica,12'
set output './results/grafico-ite.png'
set title 'Multiplicação de matrizes (iteração)'
set grid
set xrange[0:1024]
set xtics 100
set ytics 867.065
set xlabel 'Tamanho da matriz'
set ylabel 'Tempo gasto (ms)'
set xtic rotate by -90 scale 0
set yrange[0:17341.3]
plot './results/stats-ite.dat' using 1:4 title 'Tempo médio' lw 2 with lines
