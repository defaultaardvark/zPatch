%% using Matlab UDP
sender = udp('127.0.0.1', 27100); % 27100 is the default HOST_PORT_LOCAL
fopen(sender);
%%
fwrite(sender, 'Screenshot: FileName=C:/Users/Public/OR_depth'); % capture screenshot
% from desktop, filename will be appended by datetime.bmp
% fwrite(sender, 'Teensy: 1,100,4,3,100,4,3,4,0,0,0,0'); % teensy command
% fwrite(sender, 'Video: Open Window'); % open video capturing window
% fwrite(sender, 'Video: Close Window'); % close video capturing window
% fwrite(sender, 'Video: FileName=C:/or.avi'); % set capture file name
% fwrite(sender, 'Video: Start Capture'); % start capturing the video
% fwrite(sender, 'Video: Stop Capture'); % stop capturing the video
% fwrite(sender, 'Video: Preview'); % preview the video
%%
fclose(sender);


%% using pnet (faster!)
sender=pnet('udpsocket', 27100);

pnet(sender, 'write', 'Video: Start Capture', 'native'); % or other commands like before
pnet(sender, 'writepacket', '127.0.0.1', 27100);

pnet(sender, 'close');
