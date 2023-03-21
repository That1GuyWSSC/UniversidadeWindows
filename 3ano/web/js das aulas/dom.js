`use strict`

document.querySelector('.message').textContent = "🎉 Correct Number"
document.querySelector('.number').textContent = "13"
//document.querySelector('.guess').value = 23

const checkButton = document.querySelector('.check')

checkButton.addEventListener('click', function(){
    const guessNumber = Number(document.querySelector('.guess').value)
    
    if(!guessNumber){
        document.querySelector('.message').textContent = '🛑 No Number'
    }
} )
