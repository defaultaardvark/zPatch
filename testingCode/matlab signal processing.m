%Nathan Thai
%%Clear comm port
if ~isempty(instrfind)
fclose(instrfind);
delete(instrfind);
end

%%Clear all variables

clear all;
close all;

SerialPort='com5'; %serial port

TimeInterval=0.01;%time interval between each input.
loop=15;%count values

%%Set up the serial port object
s = serial(SerialPort,'BaudRate',115200);
fopen(s);

time =now;
voltage = 0;
%% Set up the figure 
figureHandle = figure('NumberTitle','off',...
    'Name','Voltage Characteristics',...
    'Color',[0 0 0],'Visible','off');
% Set axes
axesHandle = axes('Parent',figureHandle,...
    'YGrid','on',...
    'YColor',[0.9725 0.9725 0.9725],...
    'XGrid','on',...
    'XColor',[0.9725 0.9725 0.9725],...
    'Color',[0 0 0]);
hold on;
plotHandle = plot(axesHandle,time,voltage,'Marker','.','LineWid th',1,'Color',[0 1 0]);
xlim(axesHandle,[min(time) max(time+0.001)]);
xlabel('Time','FontWeight','bold','FontSize',14,'C olor',[1 1 0]);
ylabel('Voltage in V','FontWeight','bold','FontSize',14,'Color',[1 1 0]);
title('Real Time Data','FontSize',15,'Color',[1 1 0]);

%% Initializing variables
voltage(1) = 0;
time(1)=0;
count = 2;
k=1;
fwrite(s,1,'int'); %write data

while ~isequal(count,loop) 


%Serial data accessing 
voltage(count) = fscanf(s,'%f',1);
voltage = a.analogRead(0)
time(count) = count;
set(plotHandle,'YData',voltage,'XData',time);
set(figureHandle,'Visible','on');
datetick('x','mm/DD HH:MM');

pause(TimeInterval);
count = count +1;
end
fwrite(s,2,'int'); %write data

%% Clean up the serial port
fclose(s);
delete(s);
clear s;