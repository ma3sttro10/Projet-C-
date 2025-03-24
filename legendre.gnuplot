set terminal pngcairo size 800,600
set output 'polynomes.png'
set title "Six premiers polynômes de Legendre"
set xlabel "x"
set ylabel "P_n(x)"
set grid
set yrange[-1.5:1.5]
set key outside
plot "P0.dat" using 1:2 with lines title "P_0(x)", \
     "P1.dat" using 1:2 with lines title "P_1(x)", \
     "P2.dat" using 1:2 with lines title "P_2(x)", \
     "P3.dat" using 1:2 with lines title "P_3(x)", \
     "P4.dat" using 1:2 with lines title "P_4(x)", \
     "P5.dat" using 1:2 with lines title "P_5(x)"

