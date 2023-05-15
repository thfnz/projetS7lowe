set datafile separator ','
set xlabel 'x (cm)'
set ylabel 'T (K)'
while 1{
	do for [i=1:10800]{
		# set output sprintf('./resultats/image%d.png', i)
		plot sprintf('./resultats/Tn%d.csv', i) using 1:2 with lines
	}
}
