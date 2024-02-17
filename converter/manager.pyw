import os
from pydub import AudioSegment

# Get a list of all .wav files in the current directory
wav_files = [f for f in os.listdir('.') if f.endswith('.wav')]

# Loop through the .wav files and convert them to .ogg
for wav_file in wav_files:
    audio = AudioSegment.from_wav(wav_file)
    ogg_file = os.path.splitext(wav_file)[0] + '.ogg'
    audio.export(ogg_file, format='ogg')

print("Conversion completed.")
