<?php
require_once('GPIO.php');
include("wiringpi.php");
// rotary-encoder is connected to pinmode pin 1,2 means physical pin 12,15
// Stepper motor is connected to physical pin 16,18,24,26

$g[0] = new GPIO();
$g[1] = new GPIO();
$g[2] = new GPIO();
$g[3] = new GPIO();

$g[0]->setup(7, "out");
$g[1]->setup(8,"out");
$g[2]->setup(23,"out");
$g[3]->setup(24,"out");

$x1= $y1 =$z1=0;
$step = 200;
$rev=16;
$angle = 0;
$val = 0;

$encoderpos = 0;
$encoderalast = 0;
$encodera;
pinMode(1,1);
pinMode(2,1);
digitalWrite(1,1);
digitalWrite(2,1);

for (;;){

$encodera= digitalRead(1);
  if( ($encoderalast==1) && ($encodera==0) ) {
    if(digitalRead(2)==0) {
          $y1 = $encoderpos;
          $dir ='-';
          $encoderpos=$encoderpos-1;
    }
    else
    {
      $x1 = $encoderpos;
      $dir ='+';
      $encoderpos=$encoderpos+1;
    }
    $angle=($encoderpos % $rev)*360/$rev;
$x=3000;
$step=$angle/7.2;
$z1=$x1/(7.2*2);
printf("\n Encoder Position: %3d Step:%5.2f Rotate pos:$dir",$angle,$step,$dir);

if($dir=='+') goto F;
if($dir=='-') goto R;

F:
for($i=$x1;$i<=$x1+1;$i++) {
seq5: {
$g[3]->output(23,0);
$g[2]->output(7,0);
$g[1]->output(24,0);
$g[0]->output(8,1);
usleep($x);
}
seq6: {
$g[3]->output(23,0);
$g[2]->output(7,0);
$g[1]->output(24,1);
$g[0]->output(8,0);
usleep($x);
}
seq7: {
$g[0]->output(23,0);
$g[2]->output(7,1);
$g[1]->output(24,0);
$g[3]->output(8,0);
usleep($x);
}
seq8: {
$g[3]->output(23,1);
$g[2]->output(7,0);
$g[1]->output(24,0);
$g[0]->output(8,0);
usleep($x);
}
}
goto end;

R:
for($i=$y1;$i<=$y1+1;$i++) {
seq1: {
$g[3]->output(23,1);
$g[2]->output(7,0);
$g[1]->output(24,0);
$g[0]->output(8,0);
usleep($x);
}
seq2: {
$g[3]->output(23,0);
$g[2]->output(7,1);
$g[1]->output(24,0);
$g[0]->output(8,0);
usleep($x);
}
seq3: {
$g[0]->output(23,0);
$g[2]->output(7,0);
$g[1]->output(24,1);
$g[3]->output(8,0);
usleep($x);
}
seq4: {
$g[3]->output(23,0);
$g[2]->output(7,0);
$g[1]->output(24,0);
$g[0]->output(8,1);
usleep($x);
}
}
end:
}
$encoderalast=$encodera;
}
?>
