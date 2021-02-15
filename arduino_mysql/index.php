 <?php
  include("function.php");
  
  $conn = databaseConnect();
  

  if(isset($_GET['message']))
  {
    echo $_GET['message'];
    echo "<br>";
    echo "<br>";
  }
  $sql = "SELECT * FROM arduino_data";
  $result = $conn->query($sql);

  $i=0;
  if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
      $data[$i] = array("y" => $row["nilai"], "label" => $row["id"]);
      $i++;
    }
  } 
  if (isset($data)) {
    $dataPoints = $data;
  }

  $conn->close();
?> 

<?php
      
     ?>
     <!DOCTYPE HTML>
     <html>
     <head>
     <script>
     window.onload = function () {
      
     var chart = new CanvasJS.Chart("chartContainer", {
       title: {
         text: "Earthquake data"
       },
       axisY: {
         title: "Amplitudo"
       },
       data: [{
         type: "line",
         dataPoints: <?php echo json_encode($dataPoints, JSON_NUMERIC_CHECK); ?>
       }]
     });
     chart.render();
      
     }
     </script>
     </head>
     <body>
     <div id="chartContainer" style="height: 370px; width: 100%;"></div>
     <script src="https://canvasjs.com/assets/script/canvasjs.min.js"></script>
     </body>
     </html>                              
    