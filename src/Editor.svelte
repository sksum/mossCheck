<script>
    	import { onMount } from 'svelte';

    import {CodeJar} from 'codejar/codejar.js'
    const highlight = () => {
    const code = editor.textContent
    // Do something with code and set html.
    editor.innerHTML = code
    }

    onMount(() => {
        let jar = CodeJar(document.getElementById('editor'),highlight)
    });
</script>
<div id= 'editor'>
    const hello = "new one ";
</div >

<style>
	h1 {
		color: #ff3e00;
		text-transform: uppercase;
		font-size: 4em;
		font-weight: 100;
	}

    #editor {
        border-radius: 6px;
        box-shadow: 0 2px 2px 0 rgba(0, 0, 0, 0.14), 0 1px 5px 0 rgba(0, 0, 0, 0.12), 0 3px 1px -2px rgba(0, 0, 0, 0.2);
        font-family: 'Source Code Pro', monospace;
        font-size: 14px;
        font-weight: 400;
        height: 340px;
        width:48%;
        letter-spacing: normal;
        line-height: 20px;
        padding: 10px;
        tab-size: 4;
        float:left;
    }
</style>