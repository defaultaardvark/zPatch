clc
clear
close all

% Index, Middle, Ring, and Pinky fingers
scaling = [0.023132144, 0.007605088, 0.020597115, 0.005386938]; %mV/g
extrapol = [1:100];

scaled = [];
for i = 1:size(scaling, 2)
    scaled = [scaled; scaling(i)*extrapol];
    plot(extrapol, scaled(i, :))
    hold on
end
hold off
title('Extrapolated Voltage Output')
legend('Index', 'Middle', 'Ring', 'Pinky')
xlabel('Pressure [g]')
ylabel('Voltage Output [mV]')

v = [];
for n = 1:size()
    teensy = [1, 2, 3, 4, 5];
    v = [v; teensy];
end