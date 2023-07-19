document.addEventListener('DOMContentLoaded', function() {
    var botones = document.querySelectorAll('.answers button');
  
    botones.forEach(function(boton) {
      boton.addEventListener('click', function() {
        var botonActual = this;
        
        if (botonActual.classList.contains('incorrect')) {
          botonActual.style.backgroundColor = 'red';
          alert('Wrong answer');
        } else if (botonActual.classList.contains('correct')) {
          botonActual.style.backgroundColor = 'green';
          alert('Correct answer');
        }
  
        setTimeout(function() {
          botonActual.style.backgroundColor = ''; // Restablecer el color de fondo original
        }, 3000); // 3000 milisegundos = 3 segundos
      });
    });
  });

  
  document.addEventListener('DOMContentLoaded', function() {
    var form = document.querySelector('.answers.free form');
  
    form.addEventListener('submit', function(event) {
      event.preventDefault();
  
      var input = document.querySelector('.free-input');
      var respuesta = input.value.toLowerCase();
  
      if (respuesta === 'automovil') {
        alert('Correcto');
      } else {
        alert('Incorrecto');
      }
  
      input.value = ''; // Limpiar el contenido del input después de mostrar la alerta
    });
  });
  