# Arduino UNO Gear Indicator for Manual Transmission using Hall Sensors
Learn how to create a simple gear indicator for the manual transmission of the car. For that, we will use Arduino UNO with SSD1306 128x64px IIC OLED screen and 4 Hall Sensors to measure the magnetic field of the magnet placed on the shifter handle. All the images are drawn in Photopea and converted into C-style arrays using the Image2cpp utility. For a WOKWI simulation, potentiometers are used instead of Hall sensors for testing (since WOKWI does not support Hall sensors). We will also create a custom PCB in KiCad and get it manufactured by PCBWay. If you want to follow along, having some wires and a breadboard is helpful. Good luck with your project!

**YouTube video: https://youtu.be/QixtxaAda18**

**WOKWI sketch: https://wokwi.com/projects/392232701520726017**


![THUMB_arduino_gear_indicator_2](https://github.com/upiir/arduino_gear_indicator/assets/117754156/b93e7176-d758-4ca8-81b9-18b57a6f6800)


Links from the video:
- Do you like this video? You can buy me a coffee: https://www.buymeacoffee.com/upir
- Order PCB from PCBWay: https://www.pcbway.com/project/shareproject/Arduino_UNO_Gear_Indicator_for_manual_transmission_PCB_85df5da0.html
- AH3503 Hall Sensor: https://s.click.aliexpress.com/e/_DEYCKSl
- Round magnets: https://s.click.aliexpress.com/e/_DEzBT9B
- Shifter handle: https://s.click.aliexpress.com/e/_DddI3NR
- 128x64 SSD1306 OLED Display 1.54": https://s.click.aliexpress.com/e/_DCYdWXb 
- 128x64 SSD1306 OLED Display 0.96": https://s.click.aliexpress.com/e/_DCKdvnh
- 128x64 SSD1306 OLED Display 2.42": https://s.click.aliexpress.com/e/_DFdMoTh
- Arduino UNO: https://s.click.aliexpress.com/e/_AXDw1h
- Arduino breadboard prototyping shield: https://s.click.aliexpress.com/e/_ApbCwx
- Breadboard wires: https://s.click.aliexpress.com/e/_DmMQcLB
- Arduino breadboard holder: https://github.com/LaskaKit/LaskaKit-Printed-Parts/tree/main/Arduino%20Uno%20Breadboard%20400%20Holder
- Image2cpp (convert array to image): https://javl.github.io/image2cpp/
- Photopea (online graphics editor like Photoshop): https://www.photopea.com/
- KiCad (for designing PCBs): https://www.kicad.org/

Related videos with Arduino UNO and 128x64 OLED screen:
- Arduino OLED menu: https://youtu.be/HVHVkKt-ldc
- U8g vs U8g2: https://youtu.be/K5e0lFRvZ2E
- Arduino Parking Sensor - https://youtu.be/sEWw087KOj0
- Turbo pressure gauge with Arduino and OLED display - https://youtu.be/JXmw1xOlBdk
- Arduino Car Cluster with OLED Display - https://youtu.be/El5SJelwV_0
- Knob over OLED Display - https://youtu.be/SmbcNx7tbX8
- Arduino + OLED = 3D ? - https://youtu.be/kBAcaA7NAlA
- Arduino OLED Gauge - https://youtu.be/xI6dXTA02UQ
- Smaller & Faster Arduino - https://youtu.be/4GfPQoIRqW8
- Save Image from OLED Display to PC - https://youtu.be/Ft2pRMVm44E


_This video is sponsored by PCBWay. If you use this link, you can get 10PCBs for free and only pay for shipping. At the same time, you will support my YouTube channel and I will record more videos. https://www.pcbway.com/setinvite.aspx?inviteid=572577_


Small Animation:

![arduino_gear_indicator](https://github.com/upiir/arduino_gear_indicator/assets/117754156/57929bae-6e49-4d7a-a379-d5ac6d5b4ff9)


Screenshots from the video:

![CAMTASIA_arduino_gear_indicator (Time 0_00_00;00)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/2fca31e2-eef9-472a-9231-03c10db1b5a0)
![CAMTASIA_arduino_gear_indicator (Time 0_01_07;00)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/fd25b1ae-8796-4846-bac7-a0ca88002246)
![CAMTASIA_arduino_gear_indicator (Time 0_03_15;22)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/2e322f2a-a397-4c61-84af-571ab77d3ba3)
![CAMTASIA_arduino_gear_indicator (Time 0_03_58;28)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/c1f1e6c3-5a5c-44fa-9ad2-4a8d2e63dbc3)
![CAMTASIA_arduino_gear_indicator (Time 0_04_08;13)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/362d70bd-8c87-4e23-b428-efef39114649)
![CAMTASIA_arduino_gear_indicator (Time 0_04_38;19)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/faefa1ac-b8aa-4e9e-b58e-089df9116c6b)
![CAMTASIA_arduino_gear_indicator (Time 0_06_11;13)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/12e00dc9-b4cf-4b67-bbda-6f5219672a67)
![CAMTASIA_arduino_gear_indicator (Time 0_11_21;21)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/11935997-50f3-4d92-abca-bdf42ff16fd6)
![CAMTASIA_arduino_gear_indicator (Time 0_12_23;16)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/f24e2739-1de3-4a71-b4d5-7403d14423f7)
![CAMTASIA_arduino_gear_indicator (Time 0_16_45;14)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/43ee35bb-408d-4e3f-8a99-d23fd92f0b54)
![CAMTASIA_arduino_gear_indicator (Time 0_17_45;25)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/c5974629-cd2f-447e-a4b1-0ec784b74b8e)
![CAMTASIA_arduino_gear_indicator (Time 0_19_08;22)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/ed902bb8-f555-4845-aa3d-f9a7033d4fc9)
![CAMTASIA_arduino_gear_indicator (Time 0_19_26;24)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/a561ce10-2899-4edf-9e26-d54b65c0c03e)
![CAMTASIA_arduino_gear_indicator (Time 0_19_52;01)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/3a85f063-416d-43d5-a10a-2946998227f6)
![CAMTASIA_arduino_gear_indicator (Time 0_22_43;17)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/2bfb98ea-70b1-4d09-baae-834105106916)
![CAMTASIA_arduino_gear_indicator (Time 0_23_22;21)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/bd73bdf3-bd83-417d-8d6e-f5172cbac1fc)
![CAMTASIA_arduino_gear_indicator (Time 0_27_27;18)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/68588cbf-e3ee-47e9-946b-f0441703bf6d)
![CAMTASIA_arduino_gear_indicator (Time 0_28_12;01)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/4c3f99c4-30f6-4ffd-980c-8cccfdfd0559)
![CAMTASIA_arduino_gear_indicator (Time 0_28_55;01)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/02eae9bd-ff1c-4ab0-b7bc-47e3eb62d888)
![CAMTASIA_arduino_gear_indicator (Time 0_29_01;28)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/7c08b9c8-721c-40b5-be21-3b736a4d9116)
![CAMTASIA_arduino_gear_indicator (Time 0_29_18;01)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/815666d8-8c06-4340-9641-dea6e3c0c54c)
![CAMTASIA_arduino_gear_indicator (Time 0_29_28;16)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/2fe722f3-cfcd-4411-b39b-7988cfe4a87e)
![CAMTASIA_arduino_gear_indicator (Time 0_29_48;19)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/36848a59-94b1-4ac6-8d77-20f5dfea2d41)
![CAMTASIA_arduino_gear_indicator (Time 0_29_54;05)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/b915eaf5-a760-44e0-845e-3d9d52624371)
![CAMTASIA_arduino_gear_indicator (Time 0_32_34;18)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/1d7dbe16-9235-41f5-880f-541b12f47ebb)
![CAMTASIA_arduino_gear_indicator (Time 0_36_39;12)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/e6a401d7-692f-442b-a751-63d4f495e2ef)
![CAMTASIA_arduino_gear_indicator (Time 0_37_35;21)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/0fcce2f8-d500-470b-b64b-4849f062b112)
![CAMTASIA_arduino_gear_indicator (Time 0_38_41;10)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/9b5771d2-b29a-4a76-ac56-61cd554fd8d7)
![CAMTASIA_arduino_gear_indicator (Time 0_38_57;28)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/682518a7-675c-4867-8f67-4324bd800787)
![CAMTASIA_arduino_gear_indicator (Time 0_39_13;20)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/252d0f79-5130-489f-b5e8-7346c7b1b7c0)
![CAMTASIA_arduino_gear_indicator (Time 0_39_17;28)](https://github.com/upiir/arduino_gear_indicator/assets/117754156/44b190e3-17d5-43c6-923f-8f31e7971293)





