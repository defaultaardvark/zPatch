% This is for WebCam
clc; clear all; close all;
cam = webcam(1);
teensy = serial('/dev/tty.usbmodem51592401','BaudRate',9600); % You need to change the port
fopen(teensy);

TimeInterval = 0.01;  %time interval between each input.
loop=15;%count values
time = [];
ts = []; % in seconds
frame = 250; %change the number of frame
voltage = [];
image = cell(frame,1);


%% This is supposed to graph it in real-time
for idx = 1:frame
    % Acquire a single image.
    [rgbImage, ts(idx)] = snapshot(cam);
    % Convert RGB to grayscale.
    image{idx}= rgb2gray(rgbImage);
    voltage(idx,:) = str2num(fscanf(teensy));
    index = voltage(:,1);
    middle = voltage(:,2);
    ring = voltage(:,3);
    pinky = voltage(:,4);
    thumb = voltage(:,5);
    hold on
    plot(ts(1:idx),index(1:idx),'-r');
    plot(ts(1:idx),middle(1:idx),'-r');
    plot(ts(1:idx),ring(1:idx),'-r');
    plot(ts(1:idx),pinky(1:idx),'-r');
    plot(ts(1:idx),thumb(1:idx),'-r');
    xlabel('Time [s]')
    ylabel('Voltage [V]')
    title('Finger')
    legend('Index','Middle','Ring','Pinky','Thumb');
    drawnow
    hold off
%     imshow(image{idx});
end
%% this will graph it after data has been collected
for idx = 1:frame
    % Acquire a single image.
    [rgbImage, ts(idx)] = snapshot(cam);
    % Convert RGB to grayscale.
    image{idx}= rgb2gray(rgbImage);
    voltage(idx,:) = str2num(fscanf(teensy));
    figure(1);
    imshow(image{idx});
    drawnow
end

index = voltage(:,1);
middle = voltage(:,2);
ring = voltage(:,3);
pinky = voltage(:,4);
thumb = voltage(:,5);
figure(1)
plot(ts, index)
xlabel('Time [s]')
ylabel('Voltage [V]')
title('Finger')
hold on
plot(ts, middle)
plot(ts, ring)
plot(ts, pinky)
plot(ts, thumb)
legend('Index','Middle','Ring','Pinky','Thumb')
hold off

%% This is to review the footage
for i = 1:frame
    figure(2)
    imshow(image{i})
end
%%
fclose(teensy);
delete(teensy);
clear all;
close all;
clc;